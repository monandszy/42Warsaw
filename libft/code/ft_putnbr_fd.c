
#include "libft.h"

static void recurse(int n, int fd);

void ft_putnbr_fd(int n, int fd)
{
	if (n == 0)
		ft_putchar_fd('0', fd);
	else if (n == -2147483648)
		ft_putstr_fd("-2147483648", fd);
	else if (n < 0)
	{
		ft_putchar_fd('-', fd);
		n = -n;
	}
	recurse(n, fd);
}

void recurse(int n, int fd)
{
	int tmp;

	if (n > 0)
	{
		tmp = n % 10;
		recurse(n /= 10, fd);
		ft_putchar_fd(tmp + '0', fd);
	}
}
