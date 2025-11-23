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

void	transform_pixel_row(t_data *d, t_pixel *row, int x)
{
	int		y;
	double	otx;
	double	oty;
	double	hy;
	double	hx;

	y = 0;
	hx = d->x / 2.0;
	hy = d->y / 2.0;
	otx = (x - hx);
	while (y < d->y)
	{
		oty = (hy - y);
		row->ty = (oty / hy) * d->escape_treshold;
		row->tx = (otx / hx) * d->escape_treshold;
		row++;
		y++;
	}
}

void	zoom_in(t_data *d, int (*calculate)(t_data *d, t_pixel *p, int n),
		int x, int y)
{
	t_pixel	**new;

	d->escape_treshold = d->escape_treshold / ZOOM_STEP;
	if (d->zoom->next)
	{
		d->zoom = d->zoom->next;
		mlx_put_image_to_window(d->id, d->win_id, d->zoom->img.id, 0, 0);
		return ;
	}
	new = initialize_screen(d, &transform_pixel_row);
	d->zoom = new_zoom(d->zoom, x, y, new);
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
