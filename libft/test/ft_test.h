#ifndef FT_TEST
# define FT_TEST

# include "./../code/libft.h"
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

/*
** Return Value Convention:
**  - 0: Test PASSED
**  - 1 (or any non-zero): Test FAILED
*/

// === Test functions from is_x.c ===
int	test_isalpha(void);
int	test_isdigit(void);
int	test_isalnum(void);
int	test_isascii(void);
int	test_isprint(void);

// === Test functions from to_x.c ===
int	test_toupper(void);
int	test_tolower(void);

// === Test functions from mem_mani.c ===
int	test_memset(void);
int	test_bzero(void);
int	test_memcpy(void);
int	test_memmove(void);

// === Test functions from str_mani.c ===
int	test_strlen(void);
int	test_strlcpy(void);
int	test_strlcat(void);

// === Test functions from str_search.c ===
int	test_strchr(void);
int	test_strrchr(void);
int	test_memchr(void);
int	test_strnstr(void);

// === Test functions from str_cmp.c ===
int	test_strncmp(void);
int	test_memcmp(void);

// === Test functions from misc.c ===
int	test_atoi(void);
int	test_calloc(void);
int	test_strdup(void);
int	test_itoa(void);

// == Test functions from adv_str_mani.c ===
int	test_substr(void);
int	test_strjoin(void);
int	test_strtrim(void);
int	test_split(void);
int	test_strmapi(void);
int	test_striteri(void);

// === Test functions from file_mani.c ===

int	test_putchar_fd(void);
int	test_putstr_fd(void);
int	test_putendl_fd(void);
int	test_putnbr_fd(void);
#endif
