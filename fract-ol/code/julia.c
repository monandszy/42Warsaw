/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sandrzej <sandrzej@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/14 21:18:24 by sandrzej          #+#    #+#             */
/*   Updated: 2025/11/14 18:35:08 by sandrzej         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fract_ol.h"

// 1 Left Click
// 4 Mouse Forward
// 5 Mouse Backward
static int	mouse_hook(int button, int x, int y, void *param)
{
	t_data	*d;

	d = (t_data *)param;
	if (button == 4)
		return (zoom_in(d, &calculate_julia_depth, x, y), 0);
	else if (button == 5)
		return (zoom_out(d), 0);
	return (0);
}

int	open_julia(t_pixel *origin)
{
	t_data	*d;

	d = (t_data *)malloc(sizeof(t_data));
	if (!d || initialize_graphics(d))
		return (free(d), write(2, "Error\n", 6), 1);
	if (initialize_defaults(d))
		return (free_zoom_stack(d), free(d), write(2, "Error\n", 6), 1);
	mlx_hook(d->win_id, DestroyNotify, StructureNotifyMask, &end, d);
	mlx_key_hook(d->win_id, &key_hook, d);
	mlx_mouse_hook(d->win_id, &mouse_hook, d);
	d->origin.tx = -(origin->ty);
	d->origin.ty = -(origin->tx);
	render(d, &calculate_julia_depth);
	mlx_loop(d->id);
	free_zoom_stack(d);
	mlx_destroy_window(d->id, d->win_id);
	mlx_destroy_display(d->id);
	return (free(d->id), free(d), 0);
}
