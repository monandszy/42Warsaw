#include "fract_ol.h"

void zoom_in(t_data *d, int x, int y, t_dlist *zoom)
{
  (void) x;
  (void) y;
  (void) d;
  (void) zoom;
  render(d, &calculate_mandelbrot_depth);
}

void zoom_out(t_data *d, int x, int y, t_dlist *zoom)
{
  (void) x;
  (void) y;
  (void) d;
  (void) zoom;
  render(d, &calculate_julia_depth);
}