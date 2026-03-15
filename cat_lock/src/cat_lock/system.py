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
    """Context manager to safely disable and restore GNOME shortcuts."""
    def __init__(self):
        self.original_settings = {}

    def _restore(self):
        if not self.original_settings:
            return
        print("\nRestoring system shortcuts...")
        for (schema, key), original_val in self.original_settings.items():
            subprocess.run(["gsettings", "set", schema, key, original_val])
        self.original_settings.clear()
        print("Shield removed, sleep settings restored.")

    def __enter__(self):
        print("Disabling system shortcuts (Alt+Tab, Super)...")
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