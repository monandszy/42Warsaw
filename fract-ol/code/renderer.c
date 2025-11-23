/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   renderer.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sandrzej <sandrzej@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/14 18:23:23 by sandrzej          #+#    #+#             */
/*   Updated: 2025/11/14 18:35:04 by sandrzej         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fract_ol.h"

void	render(t_data *d, int (*calculate)(t_data *d, t_pixel *p, int n))
{
	t_pixel	*p;
	char	*i;
	int		ix;
	int		iy;

	ix = 0;
	d->zoom->img.id = mlx_new_image(d->id, d->x, d->y);
	i = mlx_get_data_addr(d->zoom->img.id, &d->zoom->img.bpp, &d->zoom->img.ls,
			&d->zoom->img.e);
	d->zoom->img.start = i;
	while (ix < d->x)
	{
		iy = 0;
		while (iy < d->y)
		{
			p = &((d->zoom)->screen)[ix][iy];
			p->depth = calculate(d, p, 0);
			i = convert_color(d, &d->zoom->img, i, (p->depth));
			iy++;
		}
		ix++;
	}
	mlx_put_image_to_window(d->id, d->win_id, d->zoom->img.id, 0, 0);
}
