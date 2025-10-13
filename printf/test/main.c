
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
	//printf("[%d]", printf("%a%s %a %q %w %d %t %c %y %f %h %% a%% a%% %d %%g %d %h %%%"));
//	printf("\n");
//	printf("[%d]", printf("%d%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s", NULL));
	// if no num after . set is as 0


	printf("[%d]", printf("%p\n", &test));
	printf("[%d]", printf("%lu\n", (unsigned long) &test));
	printf("[%d]", printf("%lx\n", (unsigned long) &test));

	test(test_ft_printf(), "test_ft_printf");
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
 
 		/*printf("case: %10s | ", str);
        printf("original: (");
        int c1 = printf(str);
        printf(") "); */
        printf("ft:("); 
        int c2 = ft_printf(str);
        printf(")");
        printf("{%d}\n", c2);

    }
    return (1);
}
