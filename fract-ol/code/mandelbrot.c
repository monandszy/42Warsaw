
#include "fract_ol.h"

// 1 Left Click
// 4 Mouse Forward
// 5 Mouse Backward
static int mouse_hook(int button, int x, int y, void *param)
{
  t_data *d;

  d = (t_data *) param;
  if (button == 1)
    return(open_julia(&d->zoom->screen[x][y]), 0);
  else if (button == 4)
    return(zoom_in(d, &calculate_mandelbrot_depth, x, y), 0);
  else if (button == 5)
    return(zoom_out(d), 0);
	return (0);
}

int open_mandelbrot()
{
  t_data *d;

	d = (t_data *) malloc(sizeof(t_data));
	if (!d || initialize_graphics(d))
		return (free(d), 1);
  if (initialize_defaults(d))
    return (free_zoom_stack(d), free(d), 1);
	mlx_hook(d->win_id, DestroyNotify, StructureNotifyMask, &end, d);
	mlx_key_hook(d->win_id, &key_hook, d);
	mlx_mouse_hook(d->win_id, &mouse_hook, d);
  render(d, &calculate_mandelbrot_depth);
  mlx_string_put(d->id,d->win_id,0,50,get_color(255,0,0), "Zoom into Mandelbrot or Left click to view Julia");
	mlx_loop(d->id);
  free_zoom_stack(d);
	mlx_destroy_window(d->id, d->win_id);
	mlx_destroy_display(d->id);
	return (free(d->id), free(d), 0);
}
