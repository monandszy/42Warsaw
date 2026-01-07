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
# include <string.h>
# include <fcntl.h>

# ifndef X_EDGE
#  define X_EDGE 1000
# endif

# ifndef Y_EDGE
#  define Y_EDGE 1000
# endif

typedef struct s_img
{
	void			*id;
	int				bpp;
	int				ls;
	int				e;
	char			*start;
}					t_img;

typedef struct s_coord
{
  float x;
  float y;
  float z;
} t_coord;

typedef struct s_ambient
{
  float range; // 0.0 - 1.0
  int rgb;
} t_ambient;

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
  int rgb;
} t_sphere;

typedef struct s_plane
{
  t_coord pos;
  t_coord vector;
  int rgb;
} t_plane;

typedef struct s_cylinder
{
  t_coord pos;
  t_coord vector;
  float diameter;
  float height;
  int rgb;
} t_cylinder;


typedef enum s_type
{
  AMBIENT,
  CAMERA,
  LIGHT,
  SPHERE,
  PLANE,
  CYLINDER
} t_type;

typedef struct s_entry
{
  void *obj;
  t_type type;
} t_entry;

typedef struct s_data
{
	void			*id;
	void			*win_id;
	int				x;
	int				y;
  t_entry *entries;
  size_t elen;
}					t_data;

typedef struct s_parser_data
{
  char **objects;
  t_entry *entries;
  char **parts;
  char *file_content;
} t_parser_data;


int					key_hook(int keycode, void *param);
int					end(void *param);
int	initialize_graphics(t_data *d, char *win_name);

char	*convert_color(t_data *d, t_img *img, void *dst);
int	get_color(int r, int g, int b);

char *initialize_file(t_data *d, char *name);
int parse_file(t_data *d, char *file);

int render(t_data *d);

void	free_split(char **sp);
size_t split_len(char **spl);
void print_error(char *msg);
int error(t_parser_data *pd, char *msg);

float	ft_atof(char *str);
int	ft_is_decimal(char *str);
int	ft_is_number(char *str);

float extract_decimal(t_parser_data *pd, char *str);
int extract_number(t_parser_data *pd, char *str);
int extract_rgb(t_parser_data *pd, char *str);
void extract_coord(t_parser_data *pd, char *str, t_coord *coord);

int process_Ambient(t_parser_data *pd, char **parts, t_entry *entry);
int process_Camera(t_parser_data *pd, char **parts, t_entry *entry);
int process_Light(t_parser_data *pd, char **parts, t_entry *entry);
int process_sphere(t_parser_data *pd, char **parts, t_entry *entry);
int process_plane(t_parser_data *pd, char **parts, t_entry *entry);
int process_cylinder(t_parser_data *pd, char **parts, t_entry *entry);

#endif