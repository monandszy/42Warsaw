#include "ft_test.h"
#include <string.h>
#include <bsd/string.h>

int test_strchr(void)
{
    const char *s = "tripouille";

    struct {
        int c;
    } test_cases[] = {
        {'t'},
        {'p'},
        {'e'},
        {'z'},
        {'\0'},
        {'t' + 256},
        {0}
    };

    for (int i = 0; test_cases[i].c != 0; i++)
    {
        char *ft_ret = ft_strchr(s, test_cases[i].c);
        char *std_ret = strchr(s, test_cases[i].c);

        if (ft_ret != std_ret)
        {
            printf("FAIL: test_strchr | s: \"%s\", c: '%c' (%d)\n", s, (char)test_cases[i].c, test_cases[i].c);
            printf("Expected: %p, Got: %p\n", (void*)std_ret, (void*)ft_ret);
            return (1);
        }
    }

    char *empty = "";
    if (ft_strchr(empty, 'a') != strchr(empty, 'a'))
    {
        printf("FAIL: test_strchr | s: \"\", c: 'a'\n");
        printf("Expected: %p, Got: %p\n", (void*)strchr(empty, 'a'), (void*)ft_strchr(empty, 'a'));
        return (1);
    }
     if (ft_strchr(empty, '\0') != strchr(empty, '\0'))
    {
        printf("FAIL: test_strchr | s: \"\", c: '\\0'\n");
        printf("Expected: %p, Got: %p\n", (void*)strchr(empty, '\0'), (void*)ft_strchr(empty, '\0'));
        return (1);
    }

    return (0);
}

int test_strrchr(void)
{
    const char *s = "tripouille";
    const char *s2 = "aaaaa";

    struct {
        const char *str;
        int c;
    } test_cases[] = {
        {s, 't'},
        {s, 'p'},
        {s, 'l'},
        {s, 'z'},
        {s, '\0'},
        {s2, 'a'},
        {s, 't' + 256},
        {NULL, 0}
    };

    for (int i = 0; test_cases[i].str != NULL; i++)
    {
        char *ft_ret = ft_strrchr(test_cases[i].str, test_cases[i].c);
        char *std_ret = strrchr(test_cases[i].str, test_cases[i].c);

        if (ft_ret != std_ret)
        {
            printf("FAIL: test_strrchr | s: \"%s\", c: '%c' (%d)\n", test_cases[i].str, (char)test_cases[i].c, test_cases[i].c);
            printf("Expected: %p, Got: %p\n", (void*)std_ret, (void*)ft_ret);
            return (1);
        }
    }

    char *empty = "";
    if (ft_strrchr(empty, 'a') != strrchr(empty, 'a'))
    {
        printf("FAIL: test_strrchr | s: \"\", c: 'a'\n");
        printf("Expected: %p, Got: %p\n", (void*)strrchr(empty, 'a'), (void*)ft_strrchr(empty, 'a'));
        return (1);
    }
     if (ft_strrchr(empty, '\0') != strrchr(empty, '\0'))
    {
        printf("FAIL: test_strrchr | s: \"\", c: '\\0'\n");
        printf("Expected: %p, Got: %p\n", (void*)strrchr(empty, '\0'), (void*)ft_strrchr(empty, '\0'));
        return (1);
    }

    return (0);
}

int test_memchr(void)
{
    char s[] = "ab\0cde";

    struct {
        const void *str;
        int c;
        size_t n;
    } test_cases[] = {
        {s, 'a', 6},
        {s, 'c', 6},
        {s, '\0', 6},
        {s, 'x', 6},
        {s, 'd', 3},
        {s, 'c', 0},
        {"test", 't' + 256, 4},
        {NULL, 0, 0}
    };

    for (int i = 0; test_cases[i].str != NULL; i++)
    {
        void *ft_ret = ft_memchr(test_cases[i].str, test_cases[i].c, test_cases[i].n);
        void *std_ret = memchr(test_cases[i].str, test_cases[i].c, test_cases[i].n);

        if (ft_ret != std_ret)
        {
            printf("FAIL: test_memchr | str: '%s' c: '%c', n: %zu\n", (char *)test_cases[i].str, (char)test_cases[i].c, test_cases[i].n);
            printf("Expected: %p, Got: %p\n", std_ret, ft_ret);
            return (1);
        }
    }
    return (0);
}

int test_strnstr(void)
{
    const char *haystack = "lorem ipsum dolor sit amet";

    struct {
        const char *h;
        const char *n;
        size_t len;
    } test_cases[] = {
        {haystack, "ipsum", 15},
        {haystack, "lorem", 15},
        {haystack, "amet", 30},
        {haystack, "dolor", 15},
        {haystack, "nonexistent", 30},
        {haystack, "", 10},
        {"", "a", 1},
        {"", "", 1},
        {"abc", "abcd", 4},
        {"abc", "c", 2},
        {"abc", "c", 3},
        {"foobar", "bar", 0},
        {haystack, "ipsum", 5},
        {"aaabcabcd", "abcd", 9},
        {"unlucky", "lucky", 7},
        {"unlucky", "lucky", 6},
	{NULL, "cat", 0},
        {NULL, NULL, 0}
    };

    for (int i = 0; test_cases[i].h == NULL && test_cases[i].n == NULL; i++)
    {
        char *ft_ret = ft_strnstr(test_cases[i].h, test_cases[i].n, test_cases[i].len);
        char *std_ret = strnstr(test_cases[i].h, test_cases[i].n, test_cases[i].len);

        if (ft_ret != std_ret)
        {
            printf("FAIL: test_strnstr | haystack: \"%s\", needle: \"%s\", len: %zu\n", test_cases[i].h, test_cases[i].n, test_cases[i].len);
            printf("Expected: %p, %s, Got: %p, %s\n", (void*)std_ret, std_ret, (void*)ft_ret, ft_ret );
            return (1);
        }
    }
    return (0);
}

