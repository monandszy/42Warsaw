
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
//	printf("[%d]", printf("[%.0h] \n", "CAT"));

	test(test_count_args(), "test_count_args");
	test(test_extract_args(), "test_extract_args");
	test(test_ft_format(), "test_ft_format");
	test(test_ft_printf(), "test_ft_printf");
}

int test_count_args()
{
	struct {
		char *input;
		size_t expected;
	} c[] = {
		{"% %", 1},
		{"END", 0},
		{"END", 0},
		{"END", 0},
		{"END", 0},
		{"END", 0},
		{"END", 0},
		{"END", 0},
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
			printf("FAIL: Expected: %zu, Got: %zu\n", e, returned);
			return (1);
		}
	}
	return (0);
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
	return (1);
}
