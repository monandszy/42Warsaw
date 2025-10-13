
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
}
