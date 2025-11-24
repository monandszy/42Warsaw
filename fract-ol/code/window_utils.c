/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sandrzej <sandrzej@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/14 18:23:23 by sandrzej          #+#    #+#             */
/*   Updated: 2025/11/14 18:35:04 by sandrzej         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fract_ol.h"

// XK_Escape
// 65362 UP
// 65364 DOWN
// 65361 LEFT
// 65363 RIGHT
// S
// M
int	key_hook(int keycode, void *param)
{
	t_data	*d;
  double tx;
  double ty;

	d = (t_data *)param;
  tx = d->zoom->tx;
  ty = d->zoom->ty;
	if (keycode == 65307)
		return (end(d));
  else if (keycode == 65362)
    return(offset(d, tx, ty + d->escape_treshold));
  else if (keycode == 65364)
    return(offset(d, tx, ty - d->escape_treshold));
  else if (keycode == 65361)
    return(offset(d, tx - d->escape_treshold, ty));
  else if (keycode == 65363)
    return(offset(d, tx + d->escape_treshold, ty));
	return (0);
}

int	end(void *param)
{
	mlx_loop_end(((t_data *)param)->id);
	return (0);
}

void	free_screen(t_pixel **s)
{
	int	i;

	i = 0;
	if (s)
	{
		while (s[i])
		{
			free(s[i]);
			i++;
		}
		free(s);
	}
}

void	free_zoom_stack(t_data *d)
{
	t_pixel	**s;
	t_zoom	*zoom;
	t_zoom	*tmp;

	zoom = d->zoom;
	while (zoom->next)
		zoom = zoom->next;
	while (zoom)
	{
		tmp = zoom;
		s = zoom->screen;
		zoom = zoom->prev;
		free_screen(s);
		mlx_destroy_image(d->id, tmp->img.id);
		free(tmp);
	}
}