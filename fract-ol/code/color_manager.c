/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color_management.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sandrzej <sandrzej@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/14 18:23:23 by sandrzej          #+#    #+#             */
/*   Updated: 2025/11/14 18:35:04 by sandrzej         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fract_ol.h"

int	get_color(int r, int g, int b)
{
	int	rgb;

	rgb = r;
	rgb = (rgb << 8) + g;
	rgb = (rgb << 8) + b;
	return (rgb);
}

static void	calculate_rgb_components(int total, int *r, int *g, int *b)
{
	if (total <= MAX_DEPTH)
		*r = total;
	else
	{
		*r = MAX_DEPTH;
		total -= MAX_DEPTH;
		if (total <= MAX_DEPTH)
			*g = total;
		else
		{
			*g = MAX_DEPTH;
			total -= MAX_DEPTH;
			if (total > MAX_DEPTH)
				*b = MAX_DEPTH;
			else
				*b = total;
		}
	}
}

static unsigned int	get_pixel_color(t_data *d, int depth)
{
	int	r;
	int	g;
	int	b;
	int	total;

	r = 0;
	g = 0;
	b = 0;
	if (depth < MAX_DEPTH * 3)
	{
		total = ((long)(depth) * COLOR_STEP) / DEPTH_STEP;
		calculate_rgb_components(total, &r, &g, &b);
	}
	return (mlx_get_color_value(d->id, get_color(r, g, b)));
}

char	*convert_color(t_data *d, t_img *img, void *dst, int depth)
{
	unsigned int	color;

	color = get_pixel_color(d, depth);
	*(unsigned int *)dst = color;
	return (dst + img->bpp / 8);
}
