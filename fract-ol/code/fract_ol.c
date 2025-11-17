/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fract_ol.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sandrzej <sandrzej@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/14 15:17:11 by sandrzej          #+#    #+#             */
/*   Updated: 2025/11/14 18:27:48 by sandrzej         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "fract_ol.h"


int end(void *param)
{
	mlx_loop_end(((t_data *)param)->id);
	return (0);
}

// XK_Escape
int key_hook(int keycode, void *param)
{
	if (keycode == 65307)
		return(end(param));
	return (0);
}

// 4 Mouse Forward
// 5 Mouse Backward
int mouse_hook(int button, int x, int y, void *param)
{
  static int lock;

  if (button == 4)
  {
    while (lock == 1)
      ;
    lock = 1;
    zoom_in(x, y, param);
    lock = 0;
  }
  else if (button == 5)
  {
    while (lock == 1)
      ;
    lock = 1;
    zoom_out(x, y, param);
    lock = 0;
  }
	fflush(stdout);
	return (0);
}

static t_data *initialize_graphics()
{
	t_data *new;
	void *id;
	void *win_id;

	new = (t_data *) malloc(sizeof(t_data));
	if (!new)
		return (NULL);
	new -> x = 200;
	new -> y = 200;
	id = mlx_init();
	if (!id)
		return (free(new), NULL);
	new -> id = id;
	win_id = mlx_new_window(id, new->x, new->y, "fract-ol");
	if (!win_id)
		return (mlx_destroy_display(id), free(id), free(new), NULL);
	new -> win_id = win_id;
	return (new);
}

int main(void)
{
	t_data *d;
	
	d = initialize_graphics();
	if (!d)
		return (write(1, "Error\n", 6), 1);
	mlx_hook(d->win_id, DestroyNotify, StructureNotifyMask, &end, d);
	mlx_key_hook(d->win_id, &key_hook, d);
	mlx_mouse_hook(d->win_id, &mouse_hook, d);
	pre_render(d);
	mlx_loop(d->id);
	mlx_destroy_window(d->id, d->win_id);
	mlx_destroy_display(d->id);
	return (free(d->id), free(d), 0);
}
