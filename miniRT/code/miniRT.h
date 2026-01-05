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

int					key_hook(int keycode, void *param);
int					end(void *param);
int	initialize_graphics(t_data *d);

#endif