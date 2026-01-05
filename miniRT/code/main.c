#include "miniRT.h"

int main(void)
{
  t_data	*d;

	d = (t_data *)malloc(sizeof(t_data));

	if (!d || initialize_graphics(d))
		return (free(d), 1);
	mlx_hook(d->win_id, DestroyNotify, StructureNotifyMask, &end, d);
	mlx_key_hook(d->win_id, &key_hook, d);
	
	mlx_loop(d->id);
	mlx_destroy_window(d->id, d->win_id);
	mlx_destroy_display(d->id);
	return (free(d->id), free(d), 0);
}