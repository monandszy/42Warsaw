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

int get_color(int r, int g, int b)
{
    int rgb;

    rgb = r;
    rgb = (rgb << 8) + g;
    rgb = (rgb << 8) + b;
    return (rgb);
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

