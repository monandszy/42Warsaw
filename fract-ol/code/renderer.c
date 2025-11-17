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

void zoom_in(int x, int y, t_data *data)
{
  (void) x;
  (void) y;
  (void) data;
}
void zoom_out(int x, int y, t_data *data)
{
  (void) x;
  (void) y;
  (void) data;
}

void render(t_data *d) {
  t_pixel *p;
  int depth;
  int ix;
  int iy;

  ix = 0;
  while (ix < d->x)
  {
    iy = 0;
    
    while (iy < d->y)
    {
      p = initialize_pixel(ix, iy, d);
      depth = calculate_mandelbrot_depth(p, d);
      mlx_pixel_put(d->id, d->win_id, ix, iy, get_color(depth, depth,depth));
      free (p);
      iy++;
    }
    ix++;
  }
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
