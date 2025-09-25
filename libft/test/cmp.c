#include "ft_test.h"
#include <string.h>

int test_strncmp(void)
{
    struct {
        const char *s1;
        const char *s2;
        size_t n;
    } test_cases[] = {
        {"hello", "hello", 5},
        {"hello", "hello", 10},
        {"hello", "hello", 0},
        {"hello", "hell", 5},
        {"hell", "hello", 5},
        {"a", "b", 1},
        {"b", "a", 1},
        {"test", "testing", 4},
        {"testing", "test", 4},
//        {"\200", "\0", 1},
        {"abc", "abd", 2},
        {"abc", "abd", 3},
        {"", "", 1},
        {"a", "", 1},
        {"", "a", 1},
        {NULL, NULL, 0}
    };

    for (int i = 0; test_cases[i].s1 != NULL; ++i)
    {
        int ft_ret = ft_strncmp(test_cases[i].s1, test_cases[i].s2, test_cases[i].n);
        int std_ret = strncmp(test_cases[i].s1, test_cases[i].s2, test_cases[i].n);

        int ft_sign = (ft_ret > 0) - (ft_ret < 0);
        int std_sign = (std_ret > 0) - (std_ret < 0);

        if (ft_sign != std_sign)
        {
            printf("FAIL: test_strncmp | s1: \"%s\", s2: \"%s\", n: %zu\n", test_cases[i].s1, test_cases[i].s2, test_cases[i].n);
            printf("Expected: %d, Got: %d\n", std_ret, ft_ret);
            return (1);
        }
    }
    return (0);
}

int test_memcmp(void)
{
    char s1[] = "ab\0cde";
    char s2[] = "ab\0fgh";

    struct {
        const void *b1;
        const void *b2;
        size_t n;
    } test_cases[] = {
        {"abc", "abc", 3},
        {"abc", "abd", 3},
        {"abd", "abc", 3},
        {"abc", "abc", 0},
        {s1, s2, 3},
        {s1, s2, 4},
        {"\x01\x02\xff", "\x01\x02\xfe", 3},
        {"test", "test", 5},
        {"", "", 1},
        {NULL, NULL, 0}
    };

    for (int i = 0; test_cases[i].b1 != NULL; ++i)
    {
        int ft_ret = ft_memcmp(test_cases[i].b1, test_cases[i].b2, test_cases[i].n);
        int std_ret = memcmp(test_cases[i].b1, test_cases[i].b2, test_cases[i].n);

        int ft_sign = (ft_ret > 0) - (ft_ret < 0);
        int std_sign = (std_ret > 0) - (std_ret < 0);

        if (ft_sign != std_sign)
        {
            printf("FAIL: test_memcmp | b1: \"%s\", b2: \"%s\",n: %zu\n", (char *) test_cases[i].b1, (char *) test_cases[i].b2, test_cases[i].n);
            printf("Expected: %d, Got: %d\n", std_ret, ft_ret);
            return (1);
        }
    }
    return (0);
}
