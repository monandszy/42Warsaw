import os
import urllib.request
import json
import uuid

PHOTOS_DIR = "./photos"

def ensure_cat_image() -> str:
    """Downloads a new cat image from The Cat API if it doesn't exist, saves it, and returns the path."""
    if not os.path.exists(PHOTOS_DIR):
        os.makedirs(PHOTOS_DIR)

    api_url = "https://api.thecatapi.com/v1/images/search"
    print("Downloading new cat photo from The Cat API...")
    try:
        req = urllib.request.Request(api_url)
        with urllib.request.urlopen(req) as response:
            data = json.loads(response.read().decode())
            image_url = data[0]['url']
        
        # Determine extension
        ext = image_url.split('.')[-1]
        if '?' in ext:
            ext = ext.split('?')[0]
        if ext.lower() not in ['jpg', 'jpeg', 'png', 'gif']:
            ext = 'jpg'

        filename = f"{uuid.uuid4().hex}.{ext}"
        filepath = os.path.join(PHOTOS_DIR, filename)

        headers = {
            'User-Agent': 'Mozilla/5.0'
        }
        img_req = urllib.request.Request(image_url, headers=headers)
        with urllib.request.urlopen(img_req) as img_response, open(filepath, 'wb') as out_file:
            out_file.write(img_response.read())
            
        return filepath
    except Exception as e:
        print(f"Failed to fetch image: {e}")
        # fallback to an existing photo if possible
        photos = [p for p in os.listdir(PHOTOS_DIR) if os.path.isfile(os.path.join(PHOTOS_DIR, p))]
        if photos:
            return os.path.join(PHOTOS_DIR, photos[0])
        return ""