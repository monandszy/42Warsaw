/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initializer.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sandrzej <sandrzej@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/14 15:16:13 by sandrzej          #+#    #+#             */
/*   Updated: 2025/11/14 18:35:08 by sandrzej         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fract_ol.h"

int	initialize_graphics(t_data *d)
{
	void	*id;
	void	*win_id;

	d->x = X_EDGE;
	d->y = Y_EDGE;
	id = mlx_init();
	if (!id)
		return (1);
	d->id = id;
	win_id = mlx_new_window(id, d->x, d->y, "fract-ol");
	if (!win_id)
		return (mlx_destroy_display(id), free(id), 1);
	d->win_id = win_id;
	return (0);
}


static void	initialize_pixel_row(t_data *d, t_pixel *row_pos, int y, t_pixel *target)
{
	int		x;
	double	otx;
	double	oty;
	double	hy;
	double	hx;
  double h;

	x = 0;
	hx = d->x / 2.0;
	hy = d->y / 2.0;
  if (hx > hy)
    h = hy;
  else
    h = hx;
	oty = (hy - y);
	while (x < d->x)
	{
		otx = (x - hx);
		row_pos->ty = (oty / h) * d->escape_treshold + target->ty;
		row_pos->tx = (otx / h) * d->escape_treshold + target->tx;
		row_pos++;
		x++;
	}
}

t_pixel	**initialize_screen(t_data *d, double ofx, double ofy)
{
  static t_pixel target;
	t_pixel	**screen;
	int		i;

	screen = (t_pixel **)malloc(sizeof(t_pixel *) * (d->y + 1));
	if (!screen)
		return (NULL);
	screen[d->y] = NULL;
	i = 0;
  target.tx = ofx;
  target.ty = ofy;
	while (i < d->y)
	{
		screen[i] = (t_pixel *)malloc(sizeof(t_pixel) * (d->x + 1));
		if (!screen[i])
			return (NULL);
		initialize_pixel_row(d, screen[i], i, &target);
		i++;
	}
	return (screen);
}

t_zoom	*new_zoom(t_zoom *prev, double tx, double ty, t_pixel **screen)
{
	t_zoom	*zoom;

	zoom = (t_zoom *)malloc(sizeof(t_zoom));
	if (!zoom)
		return (NULL);
	zoom->screen = screen;
	zoom->tx = tx;
	zoom->ty = ty;
	zoom->next = NULL;
	zoom->prev = prev;
	if (prev)
		prev->next = zoom;
	return (zoom);
}

int	initialize_defaults(t_data *d)
{
	t_pixel	**screen;
	t_zoom	*zoom;

	d->escape_treshold = ESCAPE_TRESHOLD;
	d->etsq = ESCAPE_TRESHOLD * ESCAPE_TRESHOLD;
	d->max_depth = MAX_DEPTH * RESOLUTION;
	d->resolution = RESOLUTION;
  d->shift = 1;
	screen = initialize_screen(d, 0, 0);
	if (!screen)
		return (1);
	zoom = new_zoom(NULL, 0, 0, screen);
	if (!zoom)
		return (1);
	d->zoom = zoom;
	return (0);
}
