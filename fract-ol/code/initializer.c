#include "fract_ol.h"

#ifndef ESCAPE_TRESHOLD
# define ESCAPE_TRESHOLD 2.5
#endif

#ifndef MAX_DEPTH
# define MAX_DEPTH 255
#endif

#ifndef RESOLUTION
# define RESOLUTION 0.125
#endif

#ifndef EDGE
# define EDGE 1000
#endif

int initialize_graphics(t_data *d)
{
	void *id;
	void *win_id;

	d -> x = EDGE;
	d -> y = EDGE;
	id = mlx_init();
	if (!id)
		return (1);
	d -> id = id;
	win_id = mlx_new_window(id, d->x, d->y, "fract-ol");
	if (!win_id)
		return (mlx_destroy_display(id), free(id), 1);
	d -> win_id = win_id;
	return (0);
}

static void initialize_pixels(t_data *d, t_pixel *row, int x)
{
  int y;
  double otx;
  double oty;

  y = 0;
  while(y < d->y)
  {
    if (x < (d->x / 2))
      otx = -((d->x / 2) - x); // negative
    else
      otx = x - (d->x / 2); // positive
    if (y < (d->y / 2))
      oty = (d->y / 2) - y; // positive
    else
      oty = -(y - (d->y / 2)); // negative  
    row -> tx = otx / (d->x/2) * d->escape_treshold;
    row -> ty = oty / (d->y/2) * d->escape_treshold;
    row++;
    y++;
  }
}

int initialize_defaults(t_data *d)
{
  t_pixel **screen;
  int i;

  screen = (t_pixel **) malloc(sizeof(t_pixel *) * (d->x + 1));
  d -> screen = screen;
  if (!screen)
    return(1);
  screen[d -> x] = NULL;
  d -> escape_treshold = ESCAPE_TRESHOLD;
  d -> etsq = ESCAPE_TRESHOLD*ESCAPE_TRESHOLD;
  d -> max_depth = MAX_DEPTH*RESOLUTION;
  d -> resolution = RESOLUTION;
  i = 0;
  while (i < d -> x)
  {
    screen[i] = (t_pixel *) malloc(sizeof(t_pixel) * (d->y + 1));
    if (!screen[i])
      return(1);
    initialize_pixels(d, screen[i], i);
    i++;
  }
  return (0);
}