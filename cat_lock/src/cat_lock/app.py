import os
import tkinter as tk
from PIL import Image, ImageTk
from dotenv import load_dotenv, find_dotenv

# Try finding .env explicitly
env_path = find_dotenv()
if not env_path:
    # Fallback 1: Current working directory
    cwd_env = os.path.join(os.getcwd(), ".env")
    if os.path.isfile(cwd_env):
        env_path = cwd_env
    else:
        # Fallback 2: Project root if installed loosely / editable
        env_path = os.path.abspath(os.path.join(os.path.dirname(__file__), "..", "..", "..", ".env"))

if not load_dotenv(env_path):
    raise RuntimeError(f"The .env file could not be loaded! Searched: {env_path}")

def run_lock_screen():
    root = tk.Tk()
    root.title("Cat Lock")

    root.attributes("-fullscreen", True)
    root.attributes("-topmost", True)
    root.configure(bg="black")
    root.config(cursor="X_cursor")
    root.protocol("WM_DELETE_WINDOW", lambda: None)

    release_key = os.environ["RELEASE_PASSPHRASE"].lower()
    cycle_interval = int(os.environ["CYCLE_INTERVAL"])
    
    # State tracking for emergency unlock
    class EscState:
        count = 0
        typed_keys = ""

    def unlock(event):
        EscState.typed_keys += event.keysym.lower()
        if EscState.typed_keys.endswith(release_key):
            root.destroy()
        # Emergency unlock: Press 'Escape' 3 times in a row
        elif event.keysym == "Escape":
            EscState.typed_keys = ""
            EscState.count += 1
            if EscState.count >= 10:
                print("Emergency unlock triggered!")
                root.destroy()
        else:
            EscState.count = 0
            
        return "break"

    def block(event):
        return "break"

    root.bind("<Key>", unlock)
    root.bind("<Button>", block)
    root.bind("<Motion>", block)
    root.bind("<MouseWheel>", block)

    root.update_idletasks()
    screen_width = root.winfo_screenwidth()
    screen_height = root.winfo_screenheight()

    label = tk.Label(root, bg="black")
    label.pack(expand=True)

    import threading
    import time
    import glob

    BASE_DIR = os.path.dirname(os.path.dirname(os.path.dirname(__file__)))
    photos_dir = os.path.join(BASE_DIR, "photos")

    class CarouselState:
        images = []
        current_index = 0
        running = True

    def get_local_photos():
        if not os.path.exists(photos_dir):
            return []
        valid = []
        for ext in ('*.jpg', '*.jpeg', '*.png', '*.gif'):
            valid.extend(glob.glob(os.path.join(photos_dir, ext)))
        return sorted(valid)

    # Initialize the core carousel tracking logic outside of local functions securely
    # Tkinter works best with instances or completely bound scoping.
    class CarouselState:
        images = get_local_photos()
        current_index = 0
        running = True

    # Keep a reference to the PhotoImage object inside the label to prevent immediate garbage collection
    # We must also strictly prevent the garbage collector from taking our current image reference
    # during successive calls.

    def cycle_image():
        if not CarouselState.running:
            return

        new_photos = get_local_photos()
        if len(new_photos) != len(CarouselState.images):
            CarouselState.images = new_photos

        if CarouselState.images:
            if CarouselState.current_index >= len(CarouselState.images):
                CarouselState.current_index = 0

            image_path = CarouselState.images[CarouselState.current_index]
            print(f"Cycling to: {image_path}")

            try:
                img = Image.open(image_path)
                img.thumbnail((screen_width, screen_height))
                cat_img = ImageTk.PhotoImage(img) # create new reference
                
                label.configure(image=cat_img)
                label.image = cat_img # IMPORTANT: hold strictly to avoiding garbage collecting!

            except Exception as e:
                print(f"Error drawing image: {e}")

            CarouselState.current_index = (CarouselState.current_index + 1) % len(CarouselState.images)

        if cycle_interval > 0:
            # Reschedule itself reliably
            root.after(cycle_interval * 1000, cycle_image)

    # Begin cycling
    cycle_image()

    def unlock_global(event):
        try:
            key = event.char.lower() if event.char else event.keysym.lower()
            if key and len(key) == 1:
                EscState.typed_keys += key
                if len(EscState.typed_keys) > len(release_key):
                    EscState.typed_keys = EscState.typed_keys[-len(release_key):]
                
                if EscState.typed_keys == release_key:
                    CarouselState.running = False
                    root.destroy()
        except Exception:
            pass

        # Emergency unlock: Press 'Escape' 3 times in a row
        if event.keysym == "Escape":
            EscState.count += 1
            if EscState.count >= 3:
                print("Emergency unlock triggered!")
                CarouselState.running = False
                root.destroy()
        else:
            EscState.count = 0
            
        return "break"   

    def block_global(event):
        return "break"

    root.bind("<Key>", unlock_global)
    root.bind("<Button>", block_global)
    root.bind("<Motion>", block_global)
    root.bind("<MouseWheel>", block_global)

    # Force fullscreen behavior actively on Windows and grab all input strictly
    root.attributes("-fullscreen", True)
    root.attributes("-topmost", True)
    
    root.focus_force()
    root.grab_set()
    
    try:
        root.mainloop()
    except Exception as e:
        import traceback
        print(f"CRASH IN MAINLOOP: {e}")
        traceback.print_exc()
        raise