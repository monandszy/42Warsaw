/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zoom_manager.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sandrzej <sandrzej@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/14 18:23:23 by sandrzej          #+#    #+#             */
/*   Updated: 2025/11/14 18:35:04 by sandrzej         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fract_ol.h"

void	zoom_in(t_data *d, int (*calculate)(t_data *d, t_pixel *p, int n),
		int x, int y)
{
	t_pixel	**new;
  t_pixel target;
  double tx;
  double ty;

	d->escape_treshold = d->escape_treshold / ZOOM_STEP;
  target = d->zoom->screen[y][x];
  ty = target.ty;
  tx = target.tx;
	new = initialize_screen(d, tx, ty);
	d->zoom = new_zoom(d->zoom, tx, ty, new);
	render(d, calculate);
}

void	zoom_out(t_data *d)
{
	t_zoom	*tmp;

	tmp = d->zoom;
	if (!tmp->prev)
		return ;
	d->escape_treshold = d->escape_treshold * ZOOM_STEP;
	d->zoom = d->zoom->prev;
	mlx_put_image_to_window(d->id, d->win_id, d->zoom->img.id, 0, 0);
}
