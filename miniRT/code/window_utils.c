/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sandrzej <sandrzej@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/14 18:23:23 by sandrzej          #+#    #+#             */
/*   Updated: 2025/11/25 12:29:27 by sandrzej         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

// XK_Escape
int	key_hook(int keycode, void *param)
{
	t_data	*d;

	d = (t_data *)param;
	if (keycode == 65307)
		return (end(d));
	return (0);
}

int	initialize_graphics(t_data *d, char *win_name)
{
	void	*id;
	void	*win_id;

	d->x = X_EDGE;
	d->y = Y_EDGE;
	id = mlx_init();
	if (!id)
		return (1);
	d->id = id;
	win_id = mlx_new_window(id, d->x, d->y, win_name);
	if (!win_id)
		return (mlx_destroy_display(id), free(id), 1);
	d->win_id = win_id;
	return (0);
}

int	end(void *param)
{
  t_data *d = (t_data *) param;
	// mlx_loop_end(d->id);
  mlx_destroy_window(d->id, d->win_id);
	mlx_destroy_display(d->id);
  free(d->id);
  exit(0);
  return (0);
}

