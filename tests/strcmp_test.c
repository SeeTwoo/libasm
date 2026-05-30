#include <criterion/criterion.h>
#include <string.h>
#include <signal.h>
#include <stdlib.h>

#include "libasm.h"

Test(strcmp_suite, both_empty) {
	char	*s1 = "";
	char	*s2 = "";

	cr_assert_eq(ft_strcmp(s1, s2), strcmp(s1, s2), "Failed with both empty");
}

Test(strcmp_suite, one_empty) {
	char	*s1 = "";
	char	*s2 = "hello";

	cr_assert_eq(ft_strcmp(s1, s2), strcmp(s1, s2), "Failed with one empty string");
}

Test(strcmp_suite, matching_strings) {
	char	*s1 = "hello";
	char	*s2 = "hello";

	cr_assert_eq(ft_strcmp(s1, s2), strcmp(s1, s2), "Failed with matching strings");
}

Test(strcmp_suite, non_matching_non_empty) {
	char	*s1 = "hello";
	char	*s2 = "helyo";

	cr_assert_eq(ft_strcmp(s1, s2), strcmp(s1, s2), "Failed with non matching, non empty strings");
}

Test(strcmp_suite, null_pointer, .signal = SIGSEGV) {
	char	*s1 = "hello";

	ft_strcmp(NULL, s1);
}
