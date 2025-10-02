
#include "libft.h"

void ft_putnbr_fd(int n, int fd)
{
	if (n == 0)
		write(fd, "0", sizeof(char));
	while(n 
}
