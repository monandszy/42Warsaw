#include "miniRT.h"

int main(int argc, char **argv)
{
  static t_data	d;
  int fd;

  if (argc != 2)
    return (write(2, "Error\n", 6), 1);
	if (initialize_graphics(&d, argv[1]))
		return (write(2, "Error\n", 6), 1);
  fd = initialize_file(&d, argv[1]);
  if (fd < 0)
		return (write(2, "Error\n", 6), end(&d), 1);
  if (parse_file(&d, fd))
		return (write(2, "Error\n", 6), end(&d), 1);
  if (render(&d))
		return (write(2, "Error\n", 6), end(&d), 1);
	mlx_hook((&d)->win_id, DestroyNotify, StructureNotifyMask, &end, &d);
	mlx_key_hook((&d)->win_id, &key_hook, &d);
	mlx_loop((&d)->id);
	return (write(2, "Error\n", 6), 1);
}