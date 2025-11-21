#include "fract_ol.h"

#ifndef ESCAPE_TRESHOLD
# define ESCAPE_TRESHOLD 3
#endif

#ifndef MAX_DEPTH
# define MAX_DEPTH 255
#endif

#ifndef RESOLUTION
# define RESOLUTION 0.125
#endif

#ifndef X_EDGE
# define X_EDGE 1000
#endif

#ifndef Y_EDGE
# define Y_EDGE 1000
#endif

int initialize_graphics(t_data *d)
{
	void *id;
	void *win_id;

	d -> x = X_EDGE;
	d -> y = Y_EDGE;
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
  double hx;
  double hy;

  y = 0;
  hx = d->x/2;
  if (x < (hx))
    otx = -((hx) - x); // negative
  else
    otx = x - (hx); // positive
  while(y < d->y)
  {
    hy = d->y/2;
    if (y < (hy))
      oty = (hy) - y; // positive
    else
      oty = -(y - (hy)); // negative  
    row -> tx = otx / (hx) * d->escape_treshold;
    row -> ty = oty / (hy) * d->escape_treshold;
    row++;
    y++;
  }
}

t_pixel **initialize_screen(t_data *d)
{
  t_pixel **screen;
  int i;

  screen = (t_pixel **) malloc(sizeof(t_pixel *) * (d->x + 1));
  if (!screen)
    return(NULL);
  screen[d -> x] = NULL;
  i = 0;
  while (i < d -> x)
  {
    screen[i] = (t_pixel *) malloc(sizeof(t_pixel) * (d->y + 1));
    screen[i] = (t_pixel *) malloc(sizeof(t_pixel) * (d->y + 1));
    if (!screen[i])
      return(NULL);
    initialize_pixels(d, screen[i], i);
    i++;
  }
  return (screen);
}
int initialize_defaults(t_data *d)
{
  t_pixel **screen;
  t_zoom *zoom;

  d -> escape_treshold = ESCAPE_TRESHOLD;
  d -> etsq = ESCAPE_TRESHOLD*ESCAPE_TRESHOLD;
  d -> max_depth = MAX_DEPTH*RESOLUTION;
  d -> resolution = RESOLUTION;
  screen = initialize_screen(d);
  if (!screen)
    return (1);
  zoom = (t_zoom *) malloc(sizeof(t_zoom));
  zoom->screen = screen;
  zoom->x=0;
  zoom->y=0;
  zoom->target = &screen[d->x/2][d->y/2];
  zoom->next = NULL;
  zoom->prev = NULL;
  d->zoom = zoom;
  return (0);
}