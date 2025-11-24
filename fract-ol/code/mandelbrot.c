/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   madelbrot.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sandrzej <sandrzej@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/14 15:17:11 by sandrzej          #+#    #+#             */
/*   Updated: 2025/11/14 18:35:08 by sandrzej         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fract_ol.h"

// 1 Left Click
// 2 Right Click
// 4 Mouse Forward
// 5 Mouse Backward
static int	mouse_hook(int button, int x, int y, void *param)
{
	t_data	*d;

	d = (t_data *)param;
	if (button == 1)
  {
    if (d->calculate == &calculate_ship_depth)
      return (open_julia(&d->zoom->screen[y][x], &calculate_burning_depth), 0);
    else if (d->calculate == &calculate_mandelbrot_depth)
      return (open_julia(&d->zoom->screen[y][x], &calculate_julia_depth), 0);
  }
	else if (button == 4)
		return (zoom_in(d, x, y), 0);
	else if (button == 5)
		return (zoom_out(d), 0);
	return (0);
}

int	open_mandelbrot(int (*calculate)(t_data *d, t_pixel *p, int n))
{
	t_data	*d;

	d = (t_data *)malloc(sizeof(t_data));
	if (!d || initialize_graphics(d))
		return (free(d), 1);
	if (initialize_defaults(d))
		return (free_zoom_stack(d), free(d), 1);
	mlx_hook(d->win_id, DestroyNotify, StructureNotifyMask, &end, d);
	mlx_key_hook(d->win_id, &key_hook, d);
	mlx_mouse_hook(d->win_id, &mouse_hook, d);
  d->calculate = calculate;
	render(d, calculate);
	mlx_string_put(d->id, d->win_id, 0, 50, get_color(255, 0, 0),
		"Zoom into Mandelbrot or Left click to view Julia");
	mlx_loop(d->id);
	free_zoom_stack(d);
	mlx_destroy_window(d->id, d->win_id);
	mlx_destroy_display(d->id);
	return (free(d->id), free(d), 0);
}
