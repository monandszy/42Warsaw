/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fract_ol.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sandrzej <sandrzej@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/14 15:16:10 by sandrzej          #+#    #+#             */
/*   Updated: 2025/11/14 18:25:21 by sandrzej         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACT_OL_H
# define FRACT_OL_H

# include "./minilibx/mlx.h"
# include <X11/X.h>
# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <math.h> 

typedef struct s_pixel
{
	double x;
	double y;
  double tx;
  double ty;
  int depth;
} t_pixel;

typedef struct s_complex
{
  double r; // real
  double i; // imaginary
} t_complex;

typedef struct s_data
{
	void *id;
	void *win_id;
	int x;
	int y;
  int max_depth;
  int escape_treshold;
  int etsq;
  t_pixel **screen;
} t_data;


int initialize_graphics(t_data *d);
int initialize_defaults(t_data *d);
void zoom_in(int x, int y, t_data *data);
void zoom_out(int x, int y, t_data *data);
int calculate_mandelbrot_depth(t_pixel *pixel, t_data *d);

int get_color(int r, int g, int b);
int get_grayscale_color(int c);
void render(t_data *data);
void pre_render(t_data *d);

#endif
