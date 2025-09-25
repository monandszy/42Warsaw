#ifndef FT_TEST
# define FT_TEST

# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include "./../code/libft.h"

/*
** Return Value Convention:
**  - 0: Test PASSED
**  - 1 (or any non-zero): Test FAILED
*/

/*extern int ft_isalpha(int c);
extern int ft_isdigit(int c);
extern int ft_isalnum(int c);
extern int ft_isascii(int c);
extern int ft_isprint(int c); 

extern int ft_toupper(int c);
extern int ft_tolower(int c);

extern size_t ft_strlen(const char *s);
extern size_t ft_strlcpy(char *dst, const char *src, size_t size);
extern size_t ft_strlcat(char *dst, const char *src, size_t size);

extern char *ft_strchr(const char *s, int c);
extern char *ft_strrchr(const char *s, int c);
extern void *ft_memchr(const void *s, int c, size_t n);
extern char *ft_strnstr(const char *big, const char *little, size_t len);

extern void *ft_memset(void *s, int c, size_t n);
extern void ft_bzero(void *s, size_t n);
extern void *ft_memcpy(void *dest, const void *src, size_t n);
extern void *ft_memmove(void *dest, const void *src, size_t n);

extern int ft_strncmp(const char *s1, const char *s2, size_t n);
extern int ft_memcmp (const void *s1, const void *s2, size_t n);

extern int ft_atoi(const char *nptr);
extern void *ft_calloc(size_t nmemb, size_t size);
extern char *ft_strndup(const char *s, size_t n); */

// === Test functions from is_x.c ===
int test_isalpha(void);
int test_isdigit(void);
int test_isalnum(void);
int test_isascii(void);
int test_isprint(void);

// === Test functions from to_x.c ===
int test_toupper(void);
int test_tolower(void);

// === Test functions from mem_mani.c ===
int test_memset(void);
int test_bzero(void);
int test_memcpy(void);
int test_memmove(void);

// === Test functions from str_mani.c ===
int test_strlen(void);
int test_strlcpy(void);
int test_strlcat(void);

// === Test functions from str_search.c ===
int test_strchr(void);
int test_strrchr(void);
int test_memchr(void);
int test_strnstr(void);

// === Test functions from str_cmp.c ===
int test_strncmp(void);
int test_memcmp(void);

// === Test functions from misc.c ===
int test_atoi(void);
int test_calloc(void);
int test_strndup(void);

#endif
