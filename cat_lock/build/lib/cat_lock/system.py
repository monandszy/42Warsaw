import sys
import os
import subprocess
import atexit

GNOME_KEYS =[
    ("org.gnome.mutter", "overlay-key", "''"),                               
    ("org.gnome.desktop.wm.keybindings", "switch-applications", "[]"),       
    ("org.gnome.desktop.wm.keybindings", "switch-windows", "[]"),            
    ("org.gnome.desktop.wm.keybindings", "cycle-windows", "[]"),
    ("org.gnome.desktop.wm.keybindings", "cycle-windows-backward", "[]"),
    ("org.gnome.shell.keybindings", "toggle-overview", "[]"),                
]

def inhibit_sleep() -> bool:
    """Relaunches the script wrapped in systemd-inhibit. Returns False if unsupported."""
    print("Activating sleep block and cat shield...")
    try:
        os.execlp(
            "systemd-inhibit", 
            "systemd-inhibit", 
            "--what=sleep:idle", 
            "--who=CatShield", 
            "--why=Waiting for 's' key", 
            sys.executable, sys.argv[0], "inhibited"
        )
    except FileNotFoundError:
        print("systemd-inhibit not found, continuing without sleep block...")
        return False
    return True

class SystemKeyBlocker:
    """Context manager to safely disable and restore GNOME shortcuts and adjust brightness."""
    def __init__(self):
        self.original_settings = {}
        self.brightness_files = []

    def _get_brightness_files(self):
        """Find brightness control files in sysfs (Ubuntu/Linux)."""
        paths = []
        base = "/sys/class/backlight/"
        if os.path.exists(base):
            for dev in os.listdir(base):
                sys_path = os.path.join(base, dev, "brightness")
                max_path = os.path.join(base, dev, "max_brightness")
                if os.path.isfile(sys_path) and os.path.isfile(max_path) and os.access(sys_path, os.W_OK):
                    paths.append(sys_path)
        return paths

    def _set_brightness_low(self):
        self.brightness_files = []
        for sys_path in self._get_brightness_files():
            try:
                with open(sys_path, "r") as f:
                    current = f.read().strip()
                self.brightness_files.append((sys_path, current))
                
                # Try setting to 1 so the screen isn't completely black but is at lowest level
                with open(sys_path, "w") as f:
                    f.write("1\n")
            except Exception as e:
                print(f"Failed to lower brightness for {sys_path}: {e}")

    def _restore_brightness(self):
        for sys_path, original in self.brightness_files:
            try:
                with open(sys_path, "w") as f:
                    f.write(f"{original}\n")
            except Exception as e:
                print(f"Failed to restore brightness for {sys_path}: {e}")
        self.brightness_files.clear()

    def _restore(self):
        if self.original_settings:
            print("\nRestoring system shortcuts...")
            for (schema, key), original_val in self.original_settings.items():
                subprocess.run(["gsettings", "set", schema, key, original_val])
            self.original_settings.clear()
        
        self._restore_brightness()
        print("Shield removed, sleep and display settings restored.")

    def __enter__(self):
        print("Disabling system shortcuts (Alt+Tab, Super)...")
        self._set_brightness_low()
        
        for schema, key, disabled_val in GNOME_KEYS:
            try:
                result = subprocess.run(["gsettings", "get", schema, key], capture_output=True, text=True)
                if result.returncode == 0:
                    self.original_settings[(schema, key)] = result.stdout.strip()
                    subprocess.run(["gsettings", "set", schema, key, disabled_val])
            except FileNotFoundError:
                print("gsettings not found, skipping GNOME shortcut block...")
                break
        
        # Register atexit just in case the app is killed abruptly but cleanly
        atexit.register(self._restore)
        return self

    def __exit__(self, exc_type, exc_val, exc_tb):
        atexit.unregister(self._restore)
        self._restore()