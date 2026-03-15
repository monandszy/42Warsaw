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

    def update_image():
        image_path = image_getter()
        if not image_path: return
        img = Image.open(image_path)
        img.thumbnail((screen_width, screen_height))
        cat_img = ImageTk.PhotoImage(img)
        label.config(image=cat_img)
        label.image = cat_img  # Keep a reference in memory
        
        if cycle_interval > 0:
            root.after(cycle_interval * 1000, update_image)

    update_image()

    root.focus_force()
    root.grab_set()
    root.mainloop()