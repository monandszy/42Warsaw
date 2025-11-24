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

int offset(t_data *d, double tx, double ty)
{
  t_pixel	**new;

  new = initialize_screen(d, tx, ty);
  d->zoom = new_zoom(d->zoom, tx, ty, new);
  render(d, d->calculate);
  return (0);
}

void	zoom_in(t_data *d, int x, int y)
{
	t_pixel	**new;
  t_pixel target;
  double tx;
  double ty;

	d->escape_treshold = d->escape_treshold / ZOOM_STEP;
  d->shift = d->shift / SHIFT_STEP;
  target = d->zoom->screen[y][x];
  tx = target.tx;
  ty = target.ty;
	new = initialize_screen(d, tx, ty);
	d->zoom = new_zoom(d->zoom, tx, ty, new);
	render(d, d->calculate);
}

void	zoom_out(t_data *d)
{
	t_zoom	*tmp;

	tmp = d->zoom;
	if (!tmp->prev)
		return ;
	d->escape_treshold = d->escape_treshold * ZOOM_STEP;
  d->shift = d->shift * SHIFT_STEP;
	d->zoom = d->zoom->prev;
  free_screen(tmp->screen);
  mlx_destroy_image(d->id, tmp->img.id);
  free(tmp);
  d->zoom->next=NULL;
	mlx_put_image_to_window(d->id, d->win_id, d->zoom->img.id, 0, 0);
}
