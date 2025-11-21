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

void render(t_data *d, int(*calculate)(t_data *d, t_pixel *p))
{
  static t_img img;
  t_pixel *p;
  int ix;
  int iy;

  ix = 0;
  img.id = mlx_new_image(d->id, d->x, d->y);
  // if (!img->id)
  img.start = mlx_get_data_addr(img.id, &img.bpp, &img.ls, &img.e);
  char *i = img.start;
  while (ix < d->x)
  {
    iy = 0;
    while (iy < d->y)
    {
      p = &((d->zoom)->screen)[ix][iy];
      p->depth = calculate(d, p);
      i = store_color(d, &img, i, (p->depth / d->resolution));
      iy++;
    }
    ix++;
  }
  mlx_put_image_to_window(d->id,d->win_id, img.id, 0, 0);
  mlx_destroy_image(d->id, img.id);
}