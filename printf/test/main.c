
#include "ft_test.h"

void    test(int result, char *name)
{
    if (result)
    {
        printf("❌ FAILED: %s \n", name);
    }
    else
    {
        printf("✅ PASSED: %s \n", name);
    }
}

int main(void)
{
//	printf("[%d]", printf("%a%s %a %q %w %d %t %c %y %f %h %% a%% a%% %d %%g %d %h %%%"));
//	printf("\n");
//	printf("[%d]", printf("%d%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s", NULL));
	// if no num after . set is as 0

	
	test(test_alloc_args(), "test_alloc_args");
	test(test_extract_args(), "test_extract_args");
	test(test_ft_format(), "test_ft_format");
	test(test_ft_printf(), "test_ft_printf");
}

int test_alloc_args()
{
	/*struct {
		char *input;
		size_t expected;
	} c[] = {
		{"% %", 1},
		{"%a%b%c%d", 4},
		{"%#0- +.d%%", 2},
		{"%%%", 2},
		{"%", 1},
		{"%s%d", 2},
		{"END", 0},
	};
	
	for (int i = 0; i < (sizeof(c) / sizeof(c[0])); i++)
	{
		char *str = c[i].input;
		size_t e = c[i].expected;
		size_t returned;
		
		returned = count_args(str);
		if (returned != e)
		{
			printf("FAIL: For: \"%s\"\n", str);
			printf("Expected: %zu, Got: %zu\n", e, returned);
			return (1);
		}
	} */
	return (1);
}

int test_extract_args()
{
	return (1);
}

int test_ft_format()
{
	return (1);
}

int test_ft_printf()
{
    struct {
        char *input;
    } c[] = {
        {"% %"},
        {"%a%b%c%d"},
        {"%#0- +.d%%"},
        {"aaaaaaaaaaa%%%%%%%"},
        {"%"},
        {"%s%d"},
        {"%#0- +%"},
		{""},
		{NULL},
        {"END"},
    };
    for (int i = 0; i < (sizeof(c) / sizeof(c[0])); i++)
    {
        char *str = c[i].input;
        size_t returned;
 
 		printf("case: %10s | ", str);
        printf("(");
        int c = printf(str);
        printf(")");
        printf("{%d}\n", c);
    }
    return (1);
}
