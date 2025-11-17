
#include "fract_ol.h"

int calculate_mandelbrot_depth(t_pixel *pixel, t_data *d)
{
  int n;
  double tmp;
  t_complex *z;
  t_complex *c;

  c = (t_complex *) malloc(sizeof(t_complex));
  c -> r = pixel -> tx;
  c -> i = pixel -> ty;

  z = (t_complex *) malloc(sizeof(t_complex));
  z -> r = 0;
  z -> i = 0;
  n = 0;
  while (n < d->max_depth)
  {
    tmp = pow(z->r, 2) + (pow(z->i, 2) * -1) + c->r;
    z->i = (2 * (z->r) * (z->i)) + c->i;
    z->r = tmp;
    if (pow(z->r, 2) + pow(z->i, 2) > (pow(d->escape_treshold, 2)))
      return (free(c), free(z), n);
    n++;
  }
  return (free(c), free(z), n);
}

int get_color(int r, int g, int b)
{
  int rgb;

  rgb = r;
  rgb = (rgb << 8) + g;
  rgb = (rgb << 8) + b;
  return (rgb);
}

t_pixel *initialize_pixel(int x, int y, t_data *d)
{
  t_pixel *new;

  new = (t_pixel *) malloc(sizeof(t_pixel));
  if (!new)
    return (NULL);
  if (x < (d->x / 2))
    new -> otx = -((d->x / 2) - x); // negative
  else
    new -> otx = x - (d->x / 2); // positive
  if (y < (d->y / 2))
    new -> oty = (d->y / 2) - y; // positive
  else
    new -> oty = -(y - (d->y / 2)); // negative

  new -> tx = new -> otx / (d->x/2) * d->escape_treshold;
  new -> ty = new -> oty / (d->y/2) * d->escape_treshold;

  return (new);
}

