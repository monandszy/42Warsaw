
#include "libft.h"

void ft_putnbr_fd(int n, int fd)
{
	if (n == 0)
		ft_putchar_fd(fd, '0');
	if (n < 0)
	{
		ft_putchar_fd(fd, "-");
		n = -n;
	}
	while (n > 0)
	{
		 ft_putchar_fd(fd, (n % 10) + '0');
		 n /= 10;
	}
}
