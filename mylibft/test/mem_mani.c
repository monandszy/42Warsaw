#include "ft_test.h"
#include <stdlib.h>
#include <string.h>

int	test_memset(void)
{
	char	ft_buf[20];
	char	std_buf[20];
	void	*ft_ret;

	struct
	{
		int c;
		size_t n;
	} test_cases[] = 
		{{'A', 10}, 
		{0, 20}, 
		{'B', 0}, 
		{255, 5}, 
		{'C', 1}, 
		{0, 0}};
	for (int i = 0; test_cases[i].n != 0 || test_cases[i].c != 0; i++)
	{
		memset(ft_buf, 'X', 20);
		memset(std_buf, 'X', 20);
		ft_ret = ft_memset(ft_buf, test_cases[i].c, test_cases[i].n);
		memset(std_buf, test_cases[i].c, test_cases[i].n);
		if (ft_ret != ft_buf)
		{
			printf("FAIL: test_memset | return (value | c: %d, n: %zu\n",
				test_cases[i].c, test_cases[i].n);
			printf("Expected: %p, Got: %p\n", (void *)ft_buf, ft_ret);
			return (1);
		}
		if (memcmp(ft_buf, std_buf, 20) != 0)
		{
			printf("FAIL: test_memset | buffer content | c: %d, n: %zu\n",
				test_cases[i].c, test_cases[i].n);
			printf("Expected buffer modified by memset,\
				Got buffer modified by ft_memset\n");
			return (1);
		}
	}
	return (0);
}

int	test_bzero(void)
{
	char	ft_buf[20];
	char	std_buf[20];
	size_t	test_sizes[] = {20, 10, 0, 1, 19};
	size_t	n;

	for (int i = 0; i < 5; i++)
	{
		n = test_sizes[i];
		memset(ft_buf, 'X', 20);
		memset(std_buf, 'X', 20);
		ft_bzero(ft_buf, n);
		bzero(std_buf, n);
		if (memcmp(ft_buf, std_buf, 20) != 0)
		{
			printf("FAIL: test_bzero | buffer content | n: %zu\n", n);
			printf("Expected: \"%s\", Got: \"%s\"\n", ft_buf, std_buf);
			return (1);
		}
	}
	return (0);
}

int	test_memcpy(void)
{
	char	src[] = "Test string for memcpy.";
	char	ft_dest[30];
	char	std_dest[30];
	size_t	test_sizes[] = {24, 10, 0, 1};
	size_t	n;
	void	*ft_ret;

	for (int i = 0; i < 4; i++)
	{
		n = test_sizes[i];
		memset(ft_dest, 'X', 30);
		memset(std_dest, 'X', 30);
		ft_ret = ft_memcpy(ft_dest, src, n);
		memcpy(std_dest, src, n);
		if (ft_ret != ft_dest)
		{
			printf("FAIL: test_memcpy | return value | n: %zu\n", n);
			printf("Expected: %p, Got: %p\n", (void *)ft_dest, ft_ret);
			return (1);
		}
		if (memcmp(ft_dest, std_dest, 30) != 0)
		{
			printf("FAIL: test_memcpy | buffer content | n: %zu\n", n);
			printf("Expected: \"%s\", Got: \"%s\"\n", std_dest, ft_dest);
			return (1);
		}
	}
	return (0);
}

int	test_memmove(void)
{
	char		ft_buf[27];
	char		std_buf[27];
	const char	*initial = "abcdefghijklmnopqrstuvwxyz";
	char		src[] = "12345";
	void		*ft_ret;

	// Test 1: No overlap
	memcpy(ft_buf, initial, 27);
	memcpy(std_buf, initial, 27);
	ft_memmove(ft_buf, src, 5);
	memmove(std_buf, src, 5);
	if (ft_memcmp(ft_buf, std_buf, 27) != 0)
	{
		printf("Expected: \"%s\", Got: \"%s\"\n", std_buf, ft_buf);
		return (1);
	}
	// Test 2: Overlap, dest > src
	memcpy(ft_buf, initial, 27);
	memcpy(std_buf, initial, 27);
	ft_ret = ft_memmove(ft_buf + 5, ft_buf, 10);
	memmove(std_buf + 5, std_buf, 10);
	if (ft_ret != ft_buf + 5)
	{
		printf("FAIL: test_memmove | return value | dest > src\n");
		printf("Expected: %p, Got: %p\n", (void *)(std_buf + 5), ft_ret);
		return (1);
	}
	if (memcmp(ft_buf, std_buf, 27) != 0)
	{
		printf("FAIL: test_memmove | content, dest > src | dest: %s, src: %s, n: \
			%d \n", ft_buf + 5, ft_buf, 10);
		printf("Expected: \"%s\", Got: \"%s\"\n", std_buf, ft_buf);
		return (1);
	}
		return (0);
	// Test 3: Overlap, src > dest
	memcpy(ft_buf, initial, 27);
	memcpy(std_buf, initial, 27);
	ft_memmove(ft_buf, ft_buf + 5, 10);
	memmove(std_buf, std_buf + 5, 10);
	if (memcmp(ft_buf, std_buf, 27) != 0)
	{
		printf("FAIL: test_memmove | content, dest < src | dest: %s, src: %s, n: \
			%d \n", ft_buf, ft_buf + 5, 10);
		printf("Expected: \"%s\", Got: \"%s\"\n", std_buf, ft_buf);
		return (1);
	}
	// Test 4: n = 0
	memcpy(ft_buf, initial, 27);
	memcpy(std_buf, initial, 27);
	ft_memmove(ft_buf, ft_buf + 5, 0);
	memmove(std_buf, std_buf + 5, 0);
	if (memcmp(ft_buf, std_buf, 27) != 0)
	{
		printf("FAIL: test_memmove | n = 0\n");
		printf("Expected: \"%s\", Got: \"%s\"\n", std_buf, ft_buf);
		return (1);
	}
	return (0);
}
