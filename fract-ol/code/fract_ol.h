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
# include "./printf/ft_printf.h"
# include <X11/X.h>
# include <math.h>
# include <stdio.h>
# include <stdlib.h>
# include <time.h>
# include <unistd.h>

# ifndef ESCAPE_TRESHOLD
#  define ESCAPE_TRESHOLD 3
# endif

# ifndef MAX_DEPTH
#  define MAX_DEPTH 255
# endif

# ifndef RESOLUTION
#  define RESOLUTION 3
# endif

# ifndef X_EDGE
#  define X_EDGE 1000
# endif

# ifndef Y_EDGE
#  define Y_EDGE 1000
# endif

# ifndef COLOR_STEP
#  define COLOR_STEP 10
# endif

# ifndef DEPTH_STEP
#  define DEPTH_STEP 1
# endif

# ifndef ZOOM_STEP
#  define ZOOM_STEP 1.25
# endif

typedef struct s_img
{
	void			*id;
	int				bpp;
	int				ls;
	int				e;
	char			*start;
}					t_img;

typedef struct s_pixel
{
	double			tx;
	double			ty;
	int				depth;
}					t_pixel;

typedef struct s_complex
{
	double	r;
	double	i;
}					t_complex;

typedef struct s_zoom
{
	int				x;
	int				y;
	t_pixel			**screen;
	t_img			img;
	struct s_zoom	*next;
	struct s_zoom	*prev;
}					t_zoom;

typedef struct s_data
{
	void			*id;
	void			*win_id;
	int				x;
	int				y;
	int				max_depth;
	double			escape_treshold;
	double			resolution;
	double			etsq;
  int (*calculate)(struct s_data *d, t_pixel *p, int n);
	t_pixel			julia_origin;
	t_zoom			*zoom;
}					t_data;

int					initialize_graphics(t_data *d);
int					initialize_defaults(t_data *d);
t_pixel				**initialize_screen(t_data *d, double ofx, double ofy);
t_zoom				*new_zoom(t_zoom *prev, int x, int y, t_pixel **screen);
int					calculate_mandelbrot_depth(t_data *d,
						t_pixel *pixel, int n);
int					calculate_julia_depth(t_data *d, t_pixel *pixel, int n);
int calculate_burning_depth(t_data *d, t_pixel *pixel, int n);
int calculate_ship_depth(t_data *d, t_pixel *pixel, int n);
void				render(t_data *d,
						int (*calculate)(t_data *d, t_pixel *p, int n));

int					get_color(int r, int g, int b);
char				*convert_color(t_data *d, t_img *img, void *dst, int depth);

int					key_hook(int keycode, void *param);
int					end(void *param);
void				free_screen(t_pixel **s);
void				free_zoom_stack(t_data *data);
int					open_mandelbrot(int (*calculate)(t_data *d, t_pixel *p, int n));
int					open_julia(t_pixel *origin, int (*calculate)(t_data *d, t_pixel *p, int n));

void				zoom_in(t_data *d,
						int (*calculate)(t_data *d, t_pixel *p, int n),
						int x, int y);
void				zoom_out(t_data *d);

#endif
