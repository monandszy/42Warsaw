#include "ft_test.h"

#include <ctype.h>

int test_toupper(void)
{
    for (int i = -1; i <= 256; i++)
    {
        if (toupper(i) != ft_toupper(i))
        {
            printf("FAIL: test_toupper | char: %d \n", i);
            printf("Expected: %d, Got: %d\n", toupper(i), ft_toupper(i));
            return (1);
        }
    }
    return (0);
}

int test_tolower(void)
{
    for (int i = -1; i <= 256; i++)
    {
        if (tolower(i) != ft_tolower(i))
        {
            printf("FAIL: test_tolower | char: %d \n", i);
            printf("Expected: %d, Got: %d\n", tolower(i), ft_tolower(i));
            return (1);
        }
    }
    return (0);
}
