#include "ft_test.h"

void test(int result, char *name)
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
	printf("--- Running Libft Test Suite ---\n\n"); 

	// --- Character Classification Tests ---
	test(test_isalpha(), "test_isalpha");
	test(test_isalnum(), "test_isalnum");
	test(test_isdigit(), "test_isdigit");
	test(test_isascii(), "test_isascii");
	test(test_isprint(), "test_isprint");

	// --- Character Conversion Tests ---
	test(test_toupper(), "test_toupper"); 
	test(test_tolower(), "test_tolower"); 

	// --- Memory Manipulation Tests ---
	test(test_memset(), "test_memset"); 
	test(test_bzero(), "test_bzero"); 
	test(test_memcpy(), "test_memcpy"); 
	test(test_memmove(), "test_memmove"); 

	// --- String Manipulation Tests ---
	test(test_strlen(), "test_strlen"); 
	test(test_strlcpy(), "test_strlcpy"); 
	test(test_strlcat(), "test_strlcat"); 

	// --- String/Memory Searching Tests ---
	test(test_strchr(), "test_strchr"); 
	test(test_strrchr(), "test_strrchr"); 
	test(test_memchr(), "test_memchr"); 
	test(test_strnstr(), "test_strnstr");  

	// --- String/Memory Comparison Tests ---
	test(test_strncmp(), "test_strncmp"); 
	test(test_memcmp(), "test_memcmp"); 

	// --- Miscellaneous Tests ---
	test(test_atoi(), "test_atoi"); 
	test(test_calloc(), "test_calloc");  
	test(test_strdup(), "test_strdup");
	test(test_itoa(), "test_itoa");

	// --- Advanced String Manipulation Tests ---
	test(test_substr(), "test_substr");
	test(test_strjoin(), "test_strjoin");
	test(test_strtrim(), "test_strtrim");
	test(test_split(), "test_split");
	test(test_strmapi(), "test_strmapi");	
	test(test_striteri(), "test_striteri");

	// --- File Manimulation Tests ---
	test(test_putchar_fd(), "test_putchar_fd");
	test(test_putstr_fd(), "test_putstr_fd");
	test(test_puntendl_fd(), "test_putendl_fd");
	test(test_putnbr_fd(), "test_putnbr_fd");	
}
