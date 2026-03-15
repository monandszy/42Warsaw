import os
import urllib.request

CAT_IMG_PATH = "/tmp/unsplash_cat_bg9jOHUtmBs.jpg"
CAT_URL = "https://unsplash.com/photos/bg9jOHUtmBs/download?force=true"

def ensure_cat_image() -> str:
    """Downloads the cat image if it doesn't exist. Fails explicitly on error."""
    if not os.path.exists(CAT_IMG_PATH):
        print("Downloading cat photo from Unsplash...")
        headers = {
            'User-Agent': 'Mozilla/5.0 (X11; Linux x86_64; rv:109.0) Gecko/20100101 Firefox/112.0',
            'Accept': 'text/html,application/xhtml+xml,application/xml;q=0.9,image/webp,*/*;q=0.8'
        }
        req = urllib.request.Request(CAT_URL, headers=headers)
        with urllib.request.urlopen(req) as response, open(CAT_IMG_PATH, 'wb') as out_file:
            out_file.write(response.read())
            
    return CAT_IMG_PATH