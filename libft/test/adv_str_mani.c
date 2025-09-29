#include "ft_test.h"
#include <limits.h>
#include <string.h>

int test_substr(void)
{
    struct {
        const char*  input;
        unsigned int start;
        size_t       len;
        const char*  expected;
    } test_cases[] = {
        { "Hello, World", 7, 5, "World" },
        { "Hello, World", 0, 5, "Hello" },
        { "Programming", 3, 8, "gramming" },
        { "abcde", 2, 1, "c" },
        { "Hello", 2, 0, "" },
        { "Hello", 2, 10, "llo" }, 
        { "abc", 2, 1, "c" },
        { "abc", 3, 5, "" },
        { "abc", 4, 5, NULL },
        { "", 0, 5, "" },
        { "", 0, 0, "" },
        { "", 1, 5, NULL }, 
        { NULL, 0, 0, NULL } 
    };
	for (int i = 0; test_cases[i].input != NULL; ++i)
    {
        const char*  s = test_cases[i].input;
        unsigned int start = test_cases[i].start;
        size_t       len = test_cases[i].len;
        const char*  expected = test_cases[i].expected;
        char*        output;

        output = ft_substr(s, start, len);
		if (output == NULL && expected != NULL) {
            printf("FAIL: test_substr | s: \"%s\", start: %u, len: %zu\n", s, start, len);
            printf("Expected: %s, Got: %s\n", expected, output);
            free(output);
            return (1);
        }
		else if (output == NULL && expected == NULL)
		{}
        else if (strcmp(output, expected))
        {
            printf("FAIL: test_substr | s: \"%s\", start: %u, len: %zu\n", s, start, len);
            printf("Expected: %s, Got: %s\n", expected, output);
            free(output);
            return (1);
        }
        free(output);
    }
	return 0;
}

int test_strjoin(void)
{
    struct {
        const char *s1;
        const char *s2;
        const char *expected;
    } test_cases[] = {
        { "Hello, ", "World!", "Hello, World!" },
        { "Tripouille ", "a un gros zboub", "Tripouille a un gros zboub" },
        { "First", "Second", "FirstSecond" },
        { "", "Append this", "Append this" },
        { "Prefix this", "", "Prefix this" },
        { "", "", "" },
        { NULL, "Handle Null s1", NULL },
        { "Handle Null s2", NULL, NULL },
        { NULL, NULL, NULL },
        { "A much longer string to test memory allocation", " and another part to join with it.", "A much longer string to test memory allocation and another part to join with it." },
        { NULL, NULL, NULL }
    };

	for (int i = 0; test_cases[i].expected != NULL; ++i)
    {
        const char *s1 = test_cases[i].s1;
        const char *s2 = test_cases[i].s2;
        const char *expected = test_cases[i].expected;
        char *output;

        output = ft_strjoin(s1, s2);

        if (output == NULL || strcmp(output, expected) != 0)
        {
            printf("FAIL: test_strjoin | s1: \"%s\", s2: \"%s\"\n", s1, s2);
            printf("Expected: \"%s\", Got: \"%s\"\n", expected, output);
            free(output);
            return (1);
        }
        free(output);
    }
	return (0);
}

int test_strtrim(void)
{
    return 1;
}

int test_split(void)
{
    return 1;
}

int test_strmapi(void)
{
    return 1;
}

int test_striteri(void)
{
    return 1;
}
