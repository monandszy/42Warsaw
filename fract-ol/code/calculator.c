
#include "fract_ol.h"

int calculate_mandelbrot_depth(t_data *d, t_pixel *pixel)
{
  int n;
  double tmp;
  double zrsq;
  double zisq;
  static t_complex z;
  static t_complex c;

  c.r = pixel->tx;
  c.i = pixel->ty;
  z.r = 0;
  z.i = 0;
  n = 0;
  while (n < d->max_depth)
  {
    zrsq = z.r*z.r;
    zisq = z.i*z.i;
    tmp = zrsq + (zisq * -1) + c.r;
    z.i = (2 * (z.r) * (z.i)) + c.i;
    z.r = tmp;
    if (zrsq + zisq > d->etsq)
      return (n);
    n++;
  } 
  return (n);
}

int calculate_julia_depth(t_data *d, t_pixel *pixel)
{
  int n;
  double tmp;
  double zrsq;
  double zisq;
  static t_complex z;
  static t_complex c;

  c.r = d->origin->tx;
  c.i = d->origin->ty;
  z.r = pixel->tx;
  z.i = pixel->ty;
  n = 0;
  while (n < d->max_depth)
  {
    zrsq = z.r*z.r;
    zisq = z.i*z.i;
    tmp = zrsq + (zisq * - 1) + c.r;
    z.i = (2 * (z.r) * (z.i)) + c.i;
    z.r = tmp;
    if (zrsq + zisq > d->etsq)
      return (n);
    n++;
  } 
  return (n);
}

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
  return(get_color(c, c, c));
}
