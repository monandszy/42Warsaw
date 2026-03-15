import os
import tkinter as tk
from PIL import Image, ImageTk
from dotenv import load_dotenv, find_dotenv

# Try finding .env explicitly up the hierarchy
if not load_dotenv(find_dotenv()):
    raise RuntimeError("The .env file could not be loaded!")

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

    def unlock(event):
        if event.keysym.lower() == release_key:
            root.destroy()
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

    def unlock(event):
        if event.keysym.lower() == release_key:
            CarouselState.running = False
            root.destroy()
        return "break"   
    def block(event):
        return "break"

    root.bind("<Key>", unlock)
    root.bind("<Button>", block)
    root.bind("<Motion>", block)
    root.bind("<MouseWheel>", block)

    root.focus_force()
    root.grab_set()
    
    try:
        root.mainloop()
    except Exception as e:
        import traceback
        print(f"CRASH IN MAINLOOP: {e}")
        traceback.print_exc()
        raise