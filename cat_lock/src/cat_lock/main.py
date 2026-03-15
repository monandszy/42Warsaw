import sys
from cat_lock.system import inhibit_sleep, SystemKeyBlocker
from cat_lock.downloader import ensure_cat_image
from cat_lock.app import run_lock_screen

def cli_entry():
    # 1. Block sleep
    if len(sys.argv) < 2 or sys.argv[1] != "inhibited":
        inhibit_sleep()
        return
        
    # 3. Apply lock screen with system keys disabled via Context Manager
    with SystemKeyBlocker():
        run_lock_screen(ensure_cat_image)