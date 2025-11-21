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


// mlx_pixel_put(d->id, d->win_id, ix, iy, get_grayscale_color((-(p->depth-255))));

char *store_color(t_data *d, t_img *img, void *dst, int depth)
{
  unsigned int color;

  // if (i->e)
  color = mlx_get_color_value(d->id, get_grayscale_color(depth));
  *(unsigned int *)dst = color;
  return (dst + img->bpp/8);
}