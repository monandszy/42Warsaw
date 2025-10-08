#include "ft_test.h"

#include <bsd/string.h>
#include <string.h>

int test_strlen(void)
{
    const char *test_cases[] = {
        "",
        "a",
        "hello",
        "a slightly longer test string",
        "12345\0hidden",
	NULL
    };

    for (int i = 0; test_cases[i] != NULL; i++)
    {
        const char *str = test_cases[i];
        size_t ft_result = ft_strlen(str);
        size_t std_result = strlen(str);

        if (ft_result != std_result)
        {
            printf("FAIL: test_strlen | str: \"%s\"\n", str);
            printf("Expected: %zu, Got: %zu\n", std_result, ft_result);
            return (1);
        }
    }
       return (0);
}

int test_strlcpy(void)
{
    char ft_dest[50];
    char std_dest[50];
    const char *src = "This is a test string.";

    size_t sizes[] = {50, 23, 15, 1, 0};
    int num_tests = sizeof(sizes) / sizeof(sizes[0]);

    for (int i = 0; i < num_tests; i++)
    {
        size_t size = sizes[i];
        memset(ft_dest, 'X', sizeof(ft_dest));
        memset(std_dest, 'X', sizeof(std_dest));

        size_t ft_ret = ft_strlcpy(ft_dest, src, size);
        size_t std_ret = strlcpy(std_dest, src, size);

        if (ft_ret != std_ret)
        {
            printf("FAIL: test_strlcpy | return value | src: \"%s\", size: %zu\n", src, size);
            printf("Expected: %zu, Got: %zu\n", std_ret, ft_ret);
            return (1);
        }

        if (memcmp(ft_dest, std_dest, sizeof(ft_dest)) != 0)
        {
            printf("FAIL: test_strlcpy | buffer content | src: \"%s\", size: %zu\n", src, size);
            printf("Expected: \"%s\", Got: \"%s\"\n", std_dest, ft_dest);
            return (1);
        }
    }
    return (0);
}

int test_strlcat(void)
{
    char ft_dest[50];
    char std_dest[50];
    const char *src = " to append.";

    struct {
        const char *id;
        size_t size;
    } test_cases[] = {
        {"start", 30},
        {"start", 18},
        {"start", 10},
        {"start", 6},
        {"start", 5},
        {"", 20},
        {"start", 0},
	{"start", 1},
	{NULL, 0},
    };

    for (int i = 0; test_cases[i].id != NULL; i++)
    {
        const char *initial = test_cases[i].id;
        size_t size = test_cases[i].size;

        strcpy(ft_dest, initial);
        strcpy(std_dest, initial);

        size_t ft_ret = ft_strlcat(ft_dest, src, size);
        size_t std_ret = strlcat(std_dest, src, size);

        if (ft_ret != std_ret)
        {
            printf("FAIL: test_strlcat | return value | initial_dst: \"%s\", src: \"%s\", size: %zu\n", initial, src, size);
            printf("Expected: %zu, Got: %zu\n", std_ret, ft_ret);
            return (1);
        }
        
        if (strcmp(ft_dest, std_dest) != 0)
        {
            printf("FAIL: test_strlcat | buffer content | initial_dst: \"%s\", src: \"%s\", size: %zu\n", initial, src, size);
            printf("Expected: \"%s\", Got: \"%s\"\n", std_dest, ft_dest);
            return (1);
        }
    }
    return (0);
}
