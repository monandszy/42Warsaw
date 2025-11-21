#include "fract_ol.h"

// XK_Escape
// S
// M
int key_hook(int keycode, void *param)
{
  t_data *d;

  d = (t_data *) param;
	if (keycode == 65307)
		return(end(d));
  return(0);
}

int end(void *param)
{
	mlx_loop_end(((t_data *)param)->id);
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