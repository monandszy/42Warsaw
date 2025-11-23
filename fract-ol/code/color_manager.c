#include "fract_ol.h"

int get_color(int r, int g, int b)
{
  int rgb;

  rgb = r;
  rgb = (rgb << 8) + g;
  rgb = (rgb << 8) + b;
  return (rgb);
}

int get_grayscale_color(int c)
{
  // c = 255 - c;
  return(get_color(c, c, c));
}

char *convert_color(t_data *d, t_img *img, void *dst, int depth)
{
  unsigned int color;
  int total;
  int r;
  int g;
  int b;

  r = 0;
  g = 0;
  b = 0;
 
  if (depth < MAX_DEPTH * 3) 
  {
    total = ((long)depth * COLOR_STEP) / DEPTH_STEP;
    if (total <= MAX_DEPTH) {
      r = total;
    } 
    else {
      r = MAX_DEPTH;
      total -= MAX_DEPTH; 
      if (total <= MAX_DEPTH) {
        g = total;
      } 
      else {
        g = MAX_DEPTH;
        total -= MAX_DEPTH;
        if (total > MAX_DEPTH) {
          b = MAX_DEPTH;
        } else {
          b = total;
        }
      }
    }
  }
  color = mlx_get_color_value(d->id, get_color(r,g,b));
  *(unsigned int *)dst = color;
  return (dst + img->bpp/8);
}
