
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
}

