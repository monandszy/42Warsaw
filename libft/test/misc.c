#include "ft_test.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stddef.h> 
#include <limits.h>

extern char *ft_strdup(const char *s);

int test_atoi(void)
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
        "",
        "2147483647", // INT_MAX
        "-2147483648",// INT_MIN
        "2147483648", // Overflow
        "-2147483649",// Underflow
        "3147483649",
        NULL
    };

    for (int i = 0; test_cases[i] != NULL; ++i)
    {
        int ft_ret = ft_atoi(test_cases[i]);
	    int std_ret = atoi(test_cases[i]);

        if (ft_ret != std_ret)
        {
            printf("FAIL: test_atoi | str: \"%s\"\n", test_cases[i]);
            printf("Expected: %d, Got: %d\n", std_ret, ft_ret);
            return (1);
        }
    }
    return (0);
}

int test_calloc(void)
{
    struct {
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
        {INT_MAX, 2, "overflow test 1"},
	    {3, INT_MAX, "overflow test 2"},
        {(INT_MAX / 2 + 1), 2, "exact overflow"},
        {2, 1, NULL},
        {0, 0, NULL}
    };

    for (int i = 0; test_cases[i].desc != NULL; ++i)
    {
        void *ft_ptr = ft_calloc(test_cases[i].count, test_cases[i].size);
        void *std_ptr = calloc(test_cases[i].count, test_cases[i].size);

        if ((ft_ptr == NULL) != (std_ptr == NULL))
        {
            printf("FAIL: test_calloc | allocation mismatch | case: %s\n", test_cases[i].desc);
            printf("Expected: %p, Got: %p\n", std_ptr, ft_ptr);
            free(ft_ptr);
            free(std_ptr);
            return (1);
        }

        if (std_ptr != NULL)
        {
            size_t total_size = test_cases[i].count * test_cases[i].size;
            int mem_diff = memcmp(ft_ptr, std_ptr, total_size);
            if (mem_diff != 0)
            {
                printf("FAIL: test_calloc | memory not zeroed | case: %s, mem_diff: %d\n", test_cases[i].desc, mem_diff);
            }
        }

        free(ft_ptr);
        free(std_ptr);
    }
    return (0);
}


int test_strdup(void)
{
    const char *test_cases[] = {
        "hello world",
        "",
        "a",
        "This is a longer string to test allocation.",
        "test\0hidden",
        NULL
    };

    for (int i = 0; test_cases[i] != NULL; ++i)
    {
        const char *s = test_cases[i];
        char *ft_ret = ft_strdup(s);
        char *std_ret = strdup(s);

        if ((ft_ret == NULL) != (std_ret == NULL))
        {
            printf("FAIL: test_strdup | allocation mismatch | s: \"%s\"\n", s);
            printf("Expected: %p, Got: %p\n", (void*)std_ret, (void*)ft_ret);
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

int test_itoa(void)
{
    return 1;
}
