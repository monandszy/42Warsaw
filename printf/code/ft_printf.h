#ifndef FT_PRINTF
#	define FT_PRINTF

# include "libft/libft.h"
# include <unistd.h>
# include <stdlib.h>
# include <stdarg.h>

int	ft_printf(const char *, ...);
size_t count_args(char *format);
char **extract_args(char *format, va_list args, char **master);
char *ft_format(char * format, char **master);
void ft_putstr(char *str);

#endif
