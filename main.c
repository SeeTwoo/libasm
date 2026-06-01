#include <stdio.h>
#include <errno.h>
#include <string.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

#include "libasm.h"

#define GREEN "\x1b[32m"
#define RED "\x1b[31m"
#define RESET "\x1b[0m"

static const char	big_string[100000] = {
	[0 ... 99998] = 'A',
	[99999] = '\0'
};

static const char	*empty_string = "";

static const char	*a_string = "hello";

static const char	*b_string = "hello";

static const char	*different = "hella";

int	strlen_tester(char const *s, char const *msg)
{
	if (ft_strlen(s) == strlen(s))
		return 1;
	puts(msg);
	return 0;
}

#define STRLEN_TEST_NUMBER 2
int	strlen_tests(void)
{
	int	passed = 0;
	
	passed += strlen_tester(empty_string, "ft_strlen fails on empty strings\n");
	passed += strlen_tester(big_string, "ft_strlen fails on big strings\n");
	if (passed != STRLEN_TEST_NUMBER)
		return 0;
	return 1;
}

#define STRCPY_TEST_NUMBER 2
int	strcpy_tests(void)
{
	int	passed = 0;
	char	long_buffer[100000];
	char	little_buffer[1];

	ft_strcpy(long_buffer, big_string);
	if (strcmp(long_buffer, big_string) == 0)
		passed++;
	else
		puts("ft_strcpy fails on long strings\n");
	ft_strcpy(little_buffer, empty_string);
	if (strcmp(little_buffer, empty_string) == 0)
		passed++;
	else
		puts("ft_strcpy fails on empty strings\n");
	if (passed != STRCPY_TEST_NUMBER)
		return 0;
	return 1;
}

int	strcmp_tester(char const *s1, char const *s2, char const *msg)
{
	if (strcmp(s1, s2) == ft_strcmp(s1, s2))
		return 1;
	puts(msg);
	return 0;
}

#define STRCMP_TEST_NUMBER 5
int	strcmp_tests(void)
{
	int	passed = 0;

	passed += strcmp_tester(empty_string, empty_string,
			"ft_strcmp fails with two empty strings\n");
	passed += strcmp_tester(empty_string, a_string,
			"ft_strcmp fails with an empty string in first\n");
	passed += strcmp_tester(a_string, empty_string,
			"ft_strcmp fails with an empty string in second\n");
	passed += strcmp_tester(a_string, b_string,
			"ft_strcmp fails with identical strings\n");
	passed += strcmp_tester(a_string, different,
			"ft_strcmp fails with different strings\n");
	if (passed != STRCMP_TEST_NUMBER)
		return 0;
	return 1;
}

#define TEST_NUMBER 3
int	main(void)
{
	int	passed = 0;

	passed += strlen_tests();
	passed += strcpy_tests();
	passed += strcmp_tests();
	if (passed != TEST_NUMBER)
		printf("%s FAILED %s\n", RED, RESET);
	else
		printf("%s PASSED %s\n", GREEN, RESET);
	return 0;
}
