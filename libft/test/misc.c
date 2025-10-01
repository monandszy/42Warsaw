#include "ft_test.h"
#include <limits.h>
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

extern char			*ft_strdup(const char *s);

int	test_atoi(void)
{
	const char *test_cases[] = {
	"42",
	"0",
	"",
	"1",
	"-1",
	"-42",
	"+42",
	"   123",
	" \t\n\v\f\r-123",
	"  +123",
	"123a456",
	"-42 is the answer",
	"--123",
	"++123",
	"+-123",
	"-+123",
	"a123",
	"0000000000123",
	"",
	"2147483647",  // INT_MAX
	"-2147483648", // INT_MIN
	"2147483648",  // Overflow
	"-2147483649", // Underflow
	"3147483649",
	NULL};
	for (int i = 0; test_cases[i] != NULL; i++)
	{
		int	ft_ret;
		int	std_ret;

		ft_ret = ft_atoi(test_cases[i]);
		std_ret = atoi(test_cases[i]);
		if (ft_ret != std_ret)
		{
			printf("FAIL: test_atoi | str: \"%s\"\n", test_cases[i]);
			printf("Expected: %d, Got: %d\n", std_ret, ft_ret);
			return (1);
		}
	}
	return (0);
}

int	test_calloc(void)
{
	struct
	{
		size_t count;
		size_t size;
		const char *desc;
	} test_cases[] = {
	{10, sizeof(int), "normal allocation"}, 
	{5, sizeof(char), "small allocation"}, 
	{1, 1, "single byte"}, 
	{0, 10, "zero count"}, 
	{10, 0, "zero size"}, 
	{0, 0, "zero count and size"}, 
	{(size_t)-1, 3, "overflow test 1"}, 
	{3, (size_t)-1, "overflow test 2"}, 
	{2, 1, NULL},
	{0, 0, NULL}};
	for (int i = 0; test_cases[i].desc != NULL; i++)
	{
		void	*ft_ptr;
		void	*std_ptr;
		size_t	total_size;
		int		mem_diff;

		ft_ptr = ft_calloc(test_cases[i].count, test_cases[i].size);
		std_ptr = calloc(test_cases[i].count, test_cases[i].size);
		if ((ft_ptr == NULL) != (std_ptr == NULL))
		{
			printf("FAIL: test_calloc | allocation mismatch | case: %s\n",
				test_cases[i].desc);
			printf("Expected: %p, Got: %p\n", std_ptr, ft_ptr);
			free(ft_ptr);
			free(std_ptr);
			return (1);
		}
		else if (std_ptr == NULL && ft_ptr == NULL)
		{
			free(ft_ptr);
			free(std_ptr);
			continue ;
		}
		total_size = test_cases[i].count * test_cases[i].size;
		mem_diff = memcmp(ft_ptr, std_ptr, total_size);
		if (mem_diff != 0)
		{
			printf("FAIL: test_calloc | memory not zeroed | case: %s, mem_diff: \
				%d\n", test_cases[i].desc, mem_diff);
		}
		free(ft_ptr);
		free(std_ptr);
	}
	return (0);
}

int	test_strdup(void)
{
	const char	*test_cases[] = {"hello world", "", "a",
			"This is a longer string to test allocation.", "test\0hidden",
			NULL};

	for (int i = 0; test_cases[i] != NULL; i++)
	{
		const char	*s = test_cases[i];
		char		*ft_ret;
		char		*std_ret;

		ft_ret = ft_strdup(s);
		std_ret = strdup(s);
		if ((ft_ret == NULL) != (std_ret == NULL))
		{
			printf("FAIL: test_strdup | allocation mismatch | s: \"%s\"\n", s);
			printf("Expected: %p, Got: %p\n", (void *)std_ret, (void *)ft_ret);
			free(ft_ret);
			free(std_ret);
			return (1);
		}
		if (std_ret != NULL)
		{
			if (strcmp(ft_ret, std_ret) != 0)
			{
				printf("FAIL: test_strdup | content mismatch | s: \"%s\"\n", s);
				printf("Expected: \"%s\", Got: \"%s\"\n", std_ret, ft_ret);
				free(ft_ret);
				free(std_ret);
				return (1);
			}
		}
		free(ft_ret);
		free(std_ret);
	}
	return (0);
}

int	test_itoa(void)
{
	struct
	{
		int			input;
		const char	*expected;
	} test_cases[] = {{1000203, "1000203"},
						{42, "42"},
						{-42, "-42"},
						{1, "1"},
						{-1, "-1"},
						{9, "9"},
						{-9, "-9"},
						{INT_MAX, "2147483647"}, 
							// The largest positive integer
						{INT_MIN, "-2147483648"},
							// The smallest negative integer (critical edge case)
						{INT_MAX - 1, "2147483646"},
						{INT_MIN + 1, "-2147483647"},
						{10, "10"},
						{100, "100"},
						{100000, "100000"},
						{-10, "-10"},
						{-100, "-100"},
						{99, "99"},
						{99999, "99999"},
						{-99, "-99"},
						{2, "2"},
						{16, "16"},
						{32, "32"},
						{64, "64"},
						{1024, "1024"},
						{-256, "-256"},
						{15, "15"},
						{63, "63"},
						{255, "255"},
						{-255, "-255"},
						{101, "101"},
						{700, "700"},
						{-1050, "-1050"},
						{1234567, "1234567"},
						{-9876543, "-9876543"},
						{0, "0"}};
	for (int i = 0; test_cases[i].input != 0; i++)
	{
		int	d;
		const char	*exp = test_cases[i].expected;
		char	*out;

		d = test_cases[i].input;
		out = ft_itoa(d);
		if (memcmp(out, exp, strlen(exp)))
		{
			printf("FAIL: test_itoa | d: \"%d\"\n", d);
			printf("Expected: \"%s\", Got: \"%s\"\n", exp, out);
			free(out);
			return (1);
		}
		free(out);
	}
	return (0);
}
