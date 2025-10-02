#include "ft_test.h"
#include <string.h>


int compare_sa(char **a1, char **a2)
{
	while (*a1 != NULL && *a2 != NULL)
	{
		if (strcmp(*a1, *a2))
			return 1;
		a1++;
		a2++;
	}
	if (*a1 != *a2)
		return (1); 
	return (0);
}

void free_split(char **split)
{
	while (*split != NULL)
	{
        free(*split);
		split++;
	}
}

void print_split(char **split)
{
	printf("{");
	while (*split != NULL)
	{
		printf("\"%s\"", *split);
		split++;
	}
	printf("}");
}

int test_split(void)
{
    char *expected1[] = {"hello", "world", NULL};
    char *expected2[] = {"lorem", "ipsum", "dolor", "sit", NULL};
    char *expected3[] = {"leading", "and", "trailing", NULL};
    char *expected4[] = {"oneword", NULL};
    char *expected5[] = {NULL}; 
	char *expected6[] = {"a", "b", "c", NULL};

    struct {
        char const  *s;
        char        c;
        char        **expected;
    } test_cases[] = {
        {"hello world", ' ', expected1},
        {"lorem-ipsum-dolor-sit", '-', expected2},
        {"  leading and trailing  ", ' ', expected3},
        {"oneword", ' ', expected4},
        {"", ' ', expected5},
        {"      ", ' ', expected5},
        {"a b c", ' ', expected6},
        {"--a-b-c--", '-', expected6},
        {"no_delimiter_here", 'Z', (char*[]){"no_delimiter_here", NULL}},
        {NULL, 0, NULL}
    };

	for (int i = 0; test_cases[i].s != NULL; i++)
    {
        const char *input_s = test_cases[i].s;
        char input_c = test_cases[i].c;
        char **expected = test_cases[i].expected;

        char **output = ft_split(input_s, input_c);
        if (compare_sa(output, expected))
        {
            printf("FAIL: test_ft_split | s: \"%s\", c: '%c'\n", input_s, input_c);
            printf("Expected: ");
	        print_split(expected);
            printf("\n");
            printf("Got:      ");
	    	print_split(output);
            printf("\n");
        	free_split(output);
			free(output);
            return (1);
		}
        free_split(output);
		free(output);
	}
	return (0);
}

char f_strmapi(unsigned int i, char c)
{
    return (c + i);
}

int test_strmapi(void)
{
	char (*f)(unsigned int, char);
	f = &f_strmapi;
    struct { 
        char *s;
        char *expected;
    } test_cases[] = {
		{"hello", "hfnos"},       
        {"", ""},                 
        {"123", "135"},           
        {"abcde", "acegi"},
		{NULL, NULL}
	};
    for (int i = 0; test_cases[i].s != NULL; i++)
    {
	char  *s = test_cases[i].s;
        char  *expected = test_cases[i].expected;
    	char  *out;

	out = ft_strmapi(s, f);

	if (out == NULL && expected != NULL)
        {
	    printf("FAIL: test_strmapi | s: \"%s\"\n", s);
            printf("Expected: \"%s\", Got: \"%s\"\n", expected, out);
            free(out);
            return (1);
        }
        else if (out == NULL && expected == NULL)
        {
        }
	else if (strcmp(out, expected))
	{
	    printf("FAIL: test_strmapi | s: \"%s\"\n", s);
            printf("Expected: \"%s\", Got: \"%s\"\n", expected, out);
	    free(out);
	    return (1);
	}
	free(out);
   }
	return (0);
}

void f_striteri(unsigned int i , char * c)
{
    c[i] = c[i] + i;
}

int test_striteri(void)
{
	char *buff;
	void (*f)(unsigned int, char *);
	f = &f_striteri;
    struct {     
        char *s;
        char *expected;
    } test_cases[] = {
	    {"hello", "hfnos"},
        {"", ""},
        {"123", "135"},
        {"abcde", "acegi"},
        {NULL, NULL}
    };
	buff = (char *) malloc(30 * sizeof(char));

    for (int i = 0; test_cases[i].s != NULL; i++)
    {
        char  *s = test_cases[i].s;
        char  *expected = test_cases[i].expected;

		bzero(buff, 30);
		memcpy(buff, s, strlen(s));

		ft_striteri(buff, f);

        if (buff == NULL && expected != NULL)
        {
            printf("FAIL: test_striter | s: \"%s\"\n", s);
            printf("Expected: \"%s\", Got: \"%s\"\n", expected, buff);
            return (1);
        }
        else if (buff == NULL && expected == NULL)
        {
        }
	else if (strcmp(buff, expected))
	{
		printf("FAIL: test_striter | s: \"%s\"\n", s);
	        printf("Expected: \"%s\", Got: \"%s\"\n", expected, buff);
		return (1);
	}	
    }
    free(buff);
    return (0);
}

