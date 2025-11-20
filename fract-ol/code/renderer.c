/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   renderer.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sandrzej <sandrzej@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/14 18:23:23 by sandrzej          #+#    #+#             */
/*   Updated: 2025/11/14 18:28:19 by sandrzej         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fract_ol.h"

void zoom_in(int x, int y, t_data *d)
{
  (void) x;
  (void) y;
  (void) d;
}

void zoom_out(int x, int y, t_data *d)
{
  (void) x;
  (void) y;
  (void) d;
}

void render(t_data *d) {
  t_pixel *p;
  int ix;
  int iy;

  ix = 0;
  void *img = mlx_new_image(d->id, d->x, d->y);
  int bpp = 0;
  int sl = 0;
  int e = 0;
  mlx_get_data_addr(img, &bpp, &sl, &e);
  printf("[%d, %d, %d, %d]", bpp, sl, e, mlx_get_color_value(d->id,get_grayscale_color(255)));
  // [32, 4000, 0, 16777215]
  fflush(stdout);
  
  while (ix < d->x)
  {
    iy = 0;
    while (iy < d->y)
    {
      p = &d->screen[ix][iy];
      p->depth = calculate_mandelbrot_depth(p, d);
      mlx_pixel_put(d->id, d->win_id, ix, iy, get_grayscale_color((-(p->depth-255))));
      iy++;
    }
    ix++;
  }
  mlx_put_image_to_window(d->id,d->win_id, img, 0, 0);
  mlx_destroy_image(d->id, img);
  // precalculate_next_zoom()
}

void pre_render(t_data *d)
{
  int c = 0;
  int color;
  int ix;
  int iy;

  ix = 0;
  while (ix < d->x)
  {
    iy = 0;
    color = get_color(c, c, c);
    while (iy < d->y)
    {
      mlx_pixel_put(d->id, d->win_id, ix, iy, color);
      iy++;
    }
    c++;
    if (c > 255)
      c = 0;
    ix++;
  }
}
