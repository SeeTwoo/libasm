#include <criterion/criterion.h>
#include <string.h>

#include "libasm.h"

Test(strcpy_suite, empty) {
	char	buffer[16];

	cr_assert_eq(ft_strcpy(buffer, ""), strcpy(buffer, ""), "Failed empty string");
	cr_assert_arr_eq("", buffer, strlen(""));
}

Test(strcpy_suite, simple_string) {
	char	buffer[16];

	cr_assert_eq(ft_strcpy(buffer, "hello"), strcpy(buffer, "hello"), "Failed with simple string");
	cr_assert_arr_eq("hello", buffer, strlen("hello"));
}
