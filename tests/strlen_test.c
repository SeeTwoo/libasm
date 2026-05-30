#include <criterion/criterion.h>
#include <string.h>
#include <signal.h>
#include <stdlib.h>

#include "libasm.h"

Test(strlen_suite, empty_string) {
	char	*str = "";

	cr_assert_eq(ft_strlen(str), strlen(str), "Failed on empty string");
}

Test(strlen_suite, regular_string) {
	char	*str = "hello, world !";

	cr_assert_eq(ft_strlen(str), strlen(str), "Failed on regular string");
}

Test(strlen_suite, really_long_string) {
	size_t	size = 1000000;
	char	*str = malloc(size + 1);

	if (str) {
		memset(str, 'a', size);
		str[size] = '\0';

		cr_assert_eq(ft_strlen(str), strlen(str), "Failed on 1MB string");
		free(str);
	}
}

Test(strlen_suite, null_pointer, .signal = SIGSEGV) {
	ft_strlen(NULL);
}
