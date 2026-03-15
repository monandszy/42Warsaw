import tkinter as tk
from PIL import Image, ImageTk

def run_lock_screen(image_path: str):
    root = tk.Tk()
    root.title("Cat Lock")

    root.attributes("-fullscreen", True)
    root.attributes("-topmost", True)
    root.configure(bg="black")
    root.config(cursor="X_cursor")
    root.protocol("WM_DELETE_WINDOW", lambda: None)

    def unlock(event):
        if event.keysym.lower() == 's':
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

    # We removed the fallback. If Pillow/Image breaks, the app explicitly crashes here.
    img = Image.open(image_path)
    img.thumbnail((screen_width, screen_height))
    
    cat_img = ImageTk.PhotoImage(img)
    label = tk.Label(root, image=cat_img, bg="black")
    label.image = cat_img  # Keep a reference in memory
    label.pack(expand=True)

    root.focus_force()
    root.grab_set()
    root.mainloop()