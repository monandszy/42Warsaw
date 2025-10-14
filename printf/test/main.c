
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
	printf("%d", 'X' - 'A');
	RUN_TEST("%s", "");
	RUN_TEST("%c %c %c", '0', 0, '1');
	RUN_TEST("%c %c %c", '0', 0, '1');
	 RUN_TEST("%10.1+1s", "c");
	 RUN_TEST("%10.1h", "caaaaaa");
	 RUN_TEST("%h %h %h", "caaaaaa");
	 RUN_TEST("%h%h%h", "caaaaaa");
	 RUN_TEST("%h%h%h%h%h", "caaaaaa");
	 RUN_TEST("%h", "caaaaaa");
	 RUN_TEST("%h ", "caaaaaa");
	 RUN_TEST("%-+#.120.s", "c"); 
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
    RUN_TEST("Hex: %x", -1); 
    RUN_TEST("Hex: %x", 10);
    RUN_TEST("Hex: %x", 15);
    RUN_TEST("Hex: %x", -9);
    RUN_TEST("Hex: %x", 10);
    RUN_TEST("Hex: %X", 42);
    RUN_TEST("Hex: %x", 255);
    RUN_TEST("Hex: %X", 255);
    RUN_TEST("Hex: %x", INT_MAX); 

    int a;
    RUN_TEST("Pointer: %p", &a);
    RUN_TEST("Pointer: %p", NULL);

    RUN_TEST("Hello, world without specifiers.", "");
    RUN_TEST("A percent sign: %% %%", "");
    RUN_TEST("100%% of the time, it's 50%% C, 50%% sea. %%%%%%%%", "");
    RUN_TEST("Str '%s', Dec %d, Hex %X, Char %c, Ptr %p %%", "test", -123, 123, 'Z', &a);
    RUN_TEST("%s%d%c", "str", 123, 'X'); 
	
    RUN_TEST("Left-justify (minus): |%-10s|", "left");
    RUN_TEST("Left-justify int: |%-10d|", 123);
    RUN_TEST("Zero-padding: |%010d|", 123);
    RUN_TEST("Zero-padding negative: |%010d|", -123);
    RUN_TEST("Minus overrides zero: |%-010d|", 123);
    RUN_TEST("Plus sign: %+d, %+d", 123, -123);
    RUN_TEST("Space sign: |% d|, |% d|", 123, -123);
    RUN_TEST("Plus overrides space: |%+ d|, |% +d|", 123, 123);
    RUN_TEST("Hash flag hex: %#x, %#X", 123, 123);
    RUN_TEST("Hash flag with zero: %#x", 0);

    RUN_TEST("Width on string: |%20s|", "hello");
    RUN_TEST("Width on int: |%10d|", 123);
    RUN_TEST("Precision on string: |%.3s|", "hello");
    RUN_TEST("Precision on int: |%.5d|", 123);
    RUN_TEST("Precision on zero int: |%.0d|", 0);
    RUN_TEST("Precision on zero value: |%.5d|", 0);
    RUN_TEST("Width and precision string: |%10.3s|", "hello");
    RUN_TEST("Width and precision int: |%10.5d|", 123);
    RUN_TEST("Width and precision, left-justify: |%-10.5d|", 123);

    RUN_TEST("Combo: |%-+20.10d|", 12345);
    RUN_TEST("Combo: |%#012x|", 0xabcdef);
    RUN_TEST("Combo: |% 010d|", 42);
    RUN_TEST("Pointer with width: |%20p|", &a);
    RUN_TEST("Multiple args: %s %d %c %x", "test", 42, 'Z', 42);
}
