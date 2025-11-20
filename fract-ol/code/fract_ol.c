/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fract_ol.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sandrzej <sandrzej@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/14 15:17:11 by sandrzej          #+#    #+#             */
/*   Updated: 2025/11/17 17:30:08 by sandrzej         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fract_ol.h"

int end(void *param)
{
	mlx_loop_end(((t_data *)param)->id);
	return (0);
}

// XK_Escape
// S
// M
int key_hook(int keycode, void *param)
{
  t_data *d;

  d = (t_data *) param;
	if (keycode == 65307)
		return(end(d));
  else if (keycode == 115)
    return(mlx_clear_window(d->id, d->win_id), render(d), 0);
  return(0);
}

// 1 Left Click
// 4 Mouse Forward
// 5 Mouse Backward
int mouse_hook(int button, int x, int y, void *param)
{
  t_data *d;

  d = (t_data *) param;
  // if (button == 1)
  //   return(mlx_clear_window(d->id, d->win_id), pre_render(d), 0);
  if (button == 4)
    return(mlx_clear_window(d->id, d->win_id), zoom_in(x, y, d), 0);
  else if (button == 5)
    return(mlx_clear_window(d->id, d->win_id), zoom_out(x, y, d), 0);
	return (0);
}

void free_screen(t_data *data)
{
  t_pixel   **s;
  int i;

  i = 0;
  s = data -> screen;
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

int main(void)
{
	t_data *d;

	d = (t_data *) malloc(sizeof(t_data));
	if (!d || initialize_graphics(d))
		return (free(d), write(2, "Error\n", 6), 1);
  if (initialize_defaults(d))
    return (free_screen(d), free(d), write(2, "Error\n", 6), 1);
	mlx_hook(d->win_id, DestroyNotify, StructureNotifyMask, &end, d);
	mlx_key_hook(d->win_id, &key_hook, d);
	mlx_mouse_hook(d->win_id, &mouse_hook, d);
  mlx_string_put(d->id,d->win_id,0,d->y/2,get_color(255,255,255), "Press s to start rendering. Click to view Julia");
	mlx_loop(d->id);
	mlx_destroy_window(d->id, d->win_id);
	mlx_destroy_display(d->id);
	return (free_screen(d), free(d->id), free(d), 0);
}
