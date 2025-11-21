
#include "fract_ol.h"

// 1 Left Click
// 4 Mouse Forward
// 5 Mouse Backward
static int mouse_hook(int button, int x, int y, void *param)
{
  t_data *d;

  d = (t_data *) param;
  if (button == 4)
    return(zoom_in(d, x, y), 0);
  else if (button == 5)
    return(zoom_out(d, x, y), 0);
	return (0);
}

int open_julia(t_data *m_d, int x, int y)
{
  t_data *d;

  d = (t_data *) malloc(sizeof(t_data));
	if (!d || initialize_graphics(d))
		return (free(d), write(2, "Error\n", 6), 1);
  if (initialize_defaults(d))
    return (free_screen(d), free(d), write(2, "Error\n", 6), 1);
	mlx_hook(d->win_id, DestroyNotify, StructureNotifyMask, &end, d);
	mlx_key_hook(d->win_id, &key_hook, d);
	mlx_mouse_hook(d->win_id, &mouse_hook, d);
  d -> origin = &m_d->zoom->screen[y][x];
  render(d, &calculate_julia_depth);
	mlx_loop(d->id);
	mlx_destroy_window(d->id, d->win_id);
	mlx_destroy_display(d->id);
	return (free_screen(d), free(d->id), free(d), 0);
}