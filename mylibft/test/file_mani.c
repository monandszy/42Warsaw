#include <string.h>  
#include <limits.h> 


#include "ft_test.h"

int test_putchar_fd(void)
{
    struct
    {
        char input;
        char expected[2];
    } cases[] = {
        {'A', "A"},
        {'z', "z"},
        {'0', "0"},
        {'\n', "\n"}};

    const char *filename = "test_putchar.txt";
    char buffer[10] = {0};
    int num_cases = sizeof(cases) / sizeof(cases[0]);

    for (int i = 0; i < num_cases; i++)
    {
        int fd = open(filename, O_WRONLY | O_CREAT | O_TRUNC, 0644);
        if (fd == -1) return (0);

        ft_putchar_fd(cases[i].input, fd);
        close(fd);

        fd = open(filename, O_RDONLY);
        if (fd == -1) return (0);
        read(fd, buffer, sizeof(buffer) - 1);
        close(fd);

        if (strcmp(buffer, cases[i].expected) != 0)
        {
            printf("\n   - FAIL [Case %d: input='%c']: Expected '%s', Got '%s'", i, cases[i].input, cases[i].expected, buffer);
            return (1);
        }
        memset(buffer, 0, sizeof(buffer));
    }

    remove(filename);
    return (0);
}

int test_putstr_fd(void)
{
    struct
    {
        char *input;
        char *expected;
    } cases[] = {
        {"Hello, World!", "Hello, World!"},
        {"", ""},
        {"42", "42"},
        {"Another test.", "Another test."}};

    const char *filename = "test_putstr.txt";
    char buffer[50] = {0};
    int num_cases = sizeof(cases) / sizeof(cases[0]);

    for (int i = 0; i < num_cases; i++)
    {
        int fd = open(filename, O_WRONLY | O_CREAT | O_TRUNC, 0644);
        if (fd == -1) return (0);

        ft_putstr_fd(cases[i].input, fd);
        close(fd);

        fd = open(filename, O_RDONLY);
        if (fd == -1) return (0);
        read(fd, buffer, sizeof(buffer) - 1);
        close(fd);

        if (strcmp(buffer, cases[i].expected) != 0)
        {
            printf("\n   - FAIL [Case %d: input=\"%s\"]: Expected \"%s\", Got \"%s\"", i, cases[i].input, cases[i].expected, buffer);
			return (1);
        }
        memset(buffer, 0, sizeof(buffer));
    }

    remove(filename);
    return (0);
}

int test_putendl_fd(void)
{
    struct
    {
        char *input;
        char *expected;
    } cases[] = {
        {"A line", "A line\n"},
        {"", "\n"},
        {"Another line with text.", "Another line with text.\n"}};

    const char *filename = "test_putendl.txt";
    char buffer[50] = {0};
    int num_cases = sizeof(cases) / sizeof(cases[0]);

    for (int i = 0; i < num_cases; i++)
    {
        int fd = open(filename, O_WRONLY | O_CREAT | O_TRUNC, 0644);
        if (fd == -1) return (0);

        ft_putendl_fd(cases[i].input, fd);
        close(fd);

        fd = open(filename, O_RDONLY);
        if (fd == -1) return (0);
        read(fd, buffer, sizeof(buffer) - 1);
        close(fd);

        if (strcmp(buffer, cases[i].expected) != 0)
        {
            printf("\n   - FAIL [Case %d: input=\"%s\"]: Expected \"%s\", Got \"%s\"", i, cases[i].input, cases[i].expected, buffer);
			return (1);
        }
        memset(buffer, 0, sizeof(buffer));
    }

    remove(filename);
    return (0);
}

int test_putnbr_fd(void)
{
    struct
    {
        int input;
        char *expected;
    } cases[] = {
        {42, "42"},
        {-123, "-123"},
        {0, "0"},
        {INT_MAX, "2147483647"},
        {INT_MIN, "-2147483648"},
        {-5, "-5"}};

    const char *filename = "test_putnbr.txt";
    char buffer[20] = {0};
    int num_cases = sizeof(cases) / sizeof(cases[0]);

    for (int i = 0; i < num_cases; i++)
    {
        int fd = open(filename, O_WRONLY | O_CREAT | O_TRUNC, 0644);
        if (fd == -1) return (0);

        ft_putnbr_fd(cases[i].input, fd);
        close(fd);

        fd = open(filename, O_RDONLY);
        if (fd == -1) return (0);
        read(fd, buffer, sizeof(buffer) - 1);
        close(fd);

        if (strcmp(buffer, cases[i].expected) != 0)
        {
            printf("\n   - FAIL [Case %d: input=%d]: Expected \"%s\", Got \"%s\"", i, cases[i].input, cases[i].expected, buffer);
			return (1);
        }
        memset(buffer, 0, sizeof(buffer));
    }

    remove(filename);
    return (0);
}
