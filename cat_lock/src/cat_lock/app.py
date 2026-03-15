import os
import tkinter as tk
from PIL import Image, ImageTk
from dotenv import load_dotenv

load_dotenv()

def run_lock_screen(image_getter):
    root = tk.Tk()
    root.title("Cat Lock")

    root.attributes("-fullscreen", True)
    root.attributes("-topmost", True)
    root.configure(bg="black")
    root.config(cursor="X_cursor")
    root.protocol("WM_DELETE_WINDOW", lambda: None)

    release_key = os.getenv("RELEASE_PASSPHRASE", "s").lower()
    cycle_interval = int(os.getenv("CYCLE_INTERVAL", "0"))

    def unlock(event):
        if event.keysym.lower() == release_key:
            try:
                CarouselState.running = False
            except NameError:
                pass
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
    
    # We will build a list of local images to cycle through
    # and periodically fetch a new one in the background.

    photos_dir = "./photos"
    
    class CarouselState:
        images = []
        current_index = 0
        running = True

    def get_local_photos():
        if not os.path.exists(photos_dir):
            return []
        # Return all valid image paths
        valid = []
        for ext in ('*.jpg', '*.jpeg', '*.png', '*.gif'):
            valid.extend(glob.glob(os.path.join(photos_dir, ext)))
        return sorted(valid)

    # Initial population
    CarouselState.images = get_local_photos()

    # The background thread
    def fetch_thread():
        while CarouselState.running:
            try:
                # This blocks, but it's okay because we are in a background thread
                new_img = image_getter()
                if new_img and new_img not in CarouselState.images:
                    CarouselState.images.append(new_img)
            except Exception as e:
                pass
            
            # Wait 5 minutes between new downloads to not spam the API
            # while the local carousel cycles faster, or wait CYCLE_INTERVAL if it's longer
            # Actually, let's tie the download rate to something reasonable (e.g. 5 mins)
            # and the cycle interval purely to the UI carousel.
            # But let's just use cycle_interval for both for simplicity if cycle_interval > 0, else sleep 60.
            time.sleep(max(cycle_interval if cycle_interval > 0 else 60, 60))

    threading.Thread(target=fetch_thread, daemon=True).start()

    def update_image():
        if CarouselState.images:
            # Refresh list occasionally to pick up background downloads
            CarouselState.images = get_local_photos()
            
            if CarouselState.current_index >= len(CarouselState.images):
                CarouselState.current_index = 0
                
            image_path = CarouselState.images[CarouselState.current_index]
            CarouselState.current_index = (CarouselState.current_index + 1) % len(CarouselState.images)
            
            try:
                img = Image.open(image_path)
                img.thumbnail((screen_width, screen_height))
                cat_img = ImageTk.PhotoImage(img)
                label.config(image=cat_img)
                label.image = cat_img  # Keep a reference in memory
            except Exception:
                pass

        if cycle_interval > 0:
            root.after(cycle_interval * 1000, update_image)

    # Do an immediate GUI update to show the first image right away
    update_image()

    root.focus_force()
    root.grab_set()
    root.mainloop()