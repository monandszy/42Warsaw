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

/*	// --- Miscellaneous Tests ---
	test(test_atoi(), "test_atoi"); 
	test(test_calloc(), "test_calloc");  
	test(test_strndup(), "test_strndup");  */
}
