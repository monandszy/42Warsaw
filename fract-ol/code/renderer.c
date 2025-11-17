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

void zoom_in(int x, int y, t_data *data)
{

}
void zoom_out(int x, int y, t_data *data)
{
}

int get_color(int r, int g, int b)
{
    int rgb;

    rgb = r;
    rgb = (rgb << 8) + g;
    rgb = (rgb << 8) + b;
    return (rgb);
}

int get_pixel_color()
{

}

#ifndef MAX_DEPTH
# define MAX_DEPTH 255
#endif

#ifndef ESCAPE_TRESHOLD
# define ESCAPE_TRESHOLD 2
#endif

int calculate_mandelbrot_depth(t_pixel *pixel)
{
  int n;
  double tmp;
  t_complex *z;
  t_complex *c;

  c = (t_complex *) malloc(sizeof(t_complex));
  c -> r = pixel -> tx;
  c -> i = pixel -> ty;

  z = (t_complex *) malloc(sizeof(t_complex));
  z -> r = 0;
  z -> i = 0;
  while (n < MAX_DEPTH)
  {
    tmp = (z->r * z->r) + ((z->i * z->i) * -1) + c->r;
    z->i = 2 * (z->r) * (z->i) + c->i;
    z->r = tmp;
    if ((z->r * z->r) + (z->i * z->i) > (ESCAPE_TRESHOLD * ESCAPE_TRESHOLD))
      return (n);
    n++;
  }
  return (n);
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

