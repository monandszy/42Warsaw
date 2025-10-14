
#include "ft_test.h"
#include <limits.h>

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

#define RUN_TEST(input, ...) \
    do { \
        int c1, c2; \
        printf("case: %-25s | ", input); \
        printf("original: ("); \
        fflush(stdout); \
        c1 = printf(input, __VA_ARGS__); \
        printf(") len:%d | ", c1); \
        printf("ft:("); \
        fflush(stdout); \
        c2 = ft_printf(input, __VA_ARGS__); \
        printf(") len:%d\n", c2); \
    } while (0)

int main(void)
{

    RUN_TEST("Hello, %s!", "world");
    RUN_TEST("An empty string: <%s>", "");
    RUN_TEST("A NULL string: <%s>", (char *)NULL);
    RUN_TEST("%s, %s, and %s!", "one", "two", "three");
    RUN_TEST("%s is the best", "ft_printf"); 
    RUN_TEST("The best is %s", "ft_printf"); 
    RUN_TEST("%s", "lonely string");
    RUN_TEST("a %s %", "lonely faulty string");

    RUN_TEST("The character is %c.", 'A');
    RUN_TEST("A tab: <%c>.", '\t');
    RUN_TEST("A null char: <%c>.", '\0');
    RUN_TEST("%c%c%c", 'a', 'b', 'c');
	
	RUN_TEST("Number: %d", 42);
    RUN_TEST("Number: %i", -42);
    RUN_TEST("Number: %d", 0);
    RUN_TEST("Max int: %d", INT_MAX);
    RUN_TEST("Min int: %d", INT_MIN);
    RUN_TEST("%d, %i, %d", 1, -2, 300); 

    RUN_TEST("Number: %u", 0);
    RUN_TEST("Number: %u", 42);
    RUN_TEST("Number: %u", -1);
    RUN_TEST("Max unsigned: %u", UINT_MAX); 

    RUN_TEST("Hex: %x", 0);
    RUN_TEST("Hex: %x", 42);
    RUN_TEST("Hex: %X", 42);
    RUN_TEST("Hex: %x", 255);
    RUN_TEST("Hex: %X", 255);
    RUN_TEST("Hex: %x", INT_MAX); 
    RUN_TEST("Hex: %x", -1); 

    int a;
    RUN_TEST("Pointer: %p", &a);
    RUN_TEST("Pointer: %p", NULL);

    RUN_TEST("Hello, world without specifiers.", "");
    RUN_TEST("A percent sign: %% %%", "");
    RUN_TEST("100%% of the time, it's 50%% C, 50%% sea. %%%%%%%%", "");
    RUN_TEST("Str '%s', Dec %d, Hex %X, Char %c, Ptr %p %%", "test", -123, 123, 'Z', &a);
    RUN_TEST("%s%d%c", "str", 123, 'X'); 
}
