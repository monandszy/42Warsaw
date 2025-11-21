/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fract_ol.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sandrzej <sandrzej@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/14 15:16:10 by sandrzej          #+#    #+#             */
/*   Updated: 2025/11/14 18:35:08 by sandrzej         ###   ########.fr       */
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

typedef struct s_img
{
  void *id;
  int bpp;
  int ls;
  int e;
  char *start;
} t_img;

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

typedef struct s_zoom
{
	int x;
  int y;
  t_pixel *target;
  t_pixel **screen;
	struct s_zoom	*next;
	struct s_zoom	*prev;
}					t_zoom;

typedef struct s_data
{
	void *id;
	void *win_id;
	int x;
	int y;
  int max_depth;
  double escape_treshold;
  double resolution;
  int etsq;
  t_pixel *origin;
  t_zoom *zoom;
} t_data;



int initialize_graphics(t_data *d);
int initialize_defaults(t_data *d);
void zoom_in(t_data *data, int x, int y);
void zoom_out(t_data *data, int x, int y);
int calculate_mandelbrot_depth(t_data *d, t_pixel *pixel);
int calculate_julia_depth(t_data *d, t_pixel *pixel);
void render(t_data *d, int(*calculate)(t_data *d, t_pixel *p));

int get_color(int r, int g, int b);
int get_grayscale_color(int c);
char *store_color(t_data *d, t_img *img, void *dst, int depth);

int key_hook(int keycode, void *param);
int end(void *param);
void free_screen(t_data *data);
int open_julia(t_data *m_d, int x, int y);

#endif
