#include "ft_test.h"

#include <ctype.h>

int test_isalpha(void)
{
	for (int i = -1; i <= 256; i++)
	{
		if ((isalpha(i) != 0) != (ft_isalpha(i) != 0))
		{
			printf("FAIL: test_isalpha | char: %d \n", i);
			printf("Expected: %d, Got: %d\n", isalpha(i), ft_isalpha(i));
			return (1);
		}
	}
	return (0);
}

int test_isalnum(void)
{
    for (int i = -1; i <= 256; i++)
    {
        if ((isalnum(i) != 0) != (ft_isalnum(i) != 0))
        {
            printf("FAIL: test_isalnum | char: %d \n", i);
            printf("Expected: %d, Got: %d\n", isalnum(i) != 0, ft_isalnum(i) != 0);
            return (1);
        }
    }
    return (0);
}

int test_isdigit(void)
{
    for (int i = -1; i <= 256; i++)
    {
        if ((isdigit(i) != 0) != (ft_isdigit(i) != 0))
        {
            printf("FAIL: test_isdigit | char: %d \n", i);
            printf("Expected: %d, Got: %d\n", isdigit(i) != 0, ft_isdigit(i) != 0);
            return (1);
        }
    }
    return (0);
}

int test_isascii(void)
{
    for (int i = -1; i <= 256; i++)
    {
        if ((isascii(i) != 0) != (ft_isascii(i) != 0))
        {
            printf("FAIL: test_isascii | char: %d \n", i);
            printf("Expected: %d, Got: %d\n", isascii(i) != 0, ft_isascii(i) != 0);
            return (1);
        }
    }
    return (0);
}

int test_isprint(void)
{
    for (int i = -1; i <= 256; i++)
    {
        if ((isprint(i) != 0) != (ft_isprint(i) != 0))
        {
            printf("FAIL: test_isprint | char: %d \n", i);
            printf("Expected: %d, Got: %d\n", isprint(i) != 0, ft_isprint(i) != 0);
            return (1);
        }
    }
    return (0);
}


