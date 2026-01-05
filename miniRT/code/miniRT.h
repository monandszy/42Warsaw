#ifndef MINIRT_H
#define MINIRT_H

# include "./minilibx/mlx.h"
# include "./libft/libft.h"
# include <X11/X.h>
# include <math.h>
# include <stdio.h>
# include <stdlib.h>
# include <time.h>
# include <unistd.h>

# ifndef X_EDGE
#  define X_EDGE 1000
# endif

# ifndef Y_EDGE
#  define Y_EDGE 1000
# endif

typedef struct s_data
{
	void			*id;
	void			*win_id;
	int				x;
	int				y;
}					t_data;

typedef struct s_img
{
	void			*id;
	int				bpp;
	int				ls;
	int				e;
	char			*start;
}					t_img;

typedef struct s_ambient
{
  float range; // 0.0 - 1.0
  int rgb;
} t_ambient;

typedef struct s_coord
{
  int x;
  int y;
  int z;
} t_coord;


typedef struct s_camera
{
  t_coord pos;
  t_coord vector;
  int fov;
} t_camera;

typedef struct s_light
{
  t_coord pos;
  float brightness;
  int rgb;
} t_light;

typedef struct s_sphere
{
  t_coord pos;
  float diameter;
  int color;
} t_sphere;

typedef struct s_plane
{
  t_coord pos;
  t_coord vector;
  int color;
} t_plane;

typedef struct s_cylinder
{
  t_coord pos;
  t_coord vector;
  float diameter;
  float height;
  int color;
} t_cylinder;

int					key_hook(int keycode, void *param);
int					end(void *param);
int	initialize_graphics(t_data *d);

char	*convert_color(t_data *d, t_img *img, void *dst);
int	get_color(int r, int g, int b);

#endif