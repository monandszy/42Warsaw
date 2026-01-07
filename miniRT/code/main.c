#include "miniRT.h"

int main(int argc, char **argv)
{
  static t_data	d;
  char * file;

  if (argc != 2)
    return (write(2, "Error: Invalid arg count\n", 6), 1);
  file = initialize_file(&d, argv[1]);
  if (!file)
		return (free(file), write(2, "Error: File initialization failed\n", 6), 1);
  if (parse_file(&d, file))
		return (write(2, "Error: File parsing failed\n", 6), 1);
  free(file);
  if (initialize_graphics(&d, argv[1]))
		return (write(2, "Error\n", 6), 1);
  if (render(&d))
		return (write(2, "Error\n", 6), end(&d), 1);
	mlx_hook((&d)->win_id, DestroyNotify, StructureNotifyMask, &end, &d);
	mlx_key_hook((&d)->win_id, &key_hook, &d);
	mlx_loop((&d)->id);
	return (write(2, "Error\n", 6), 1);
}