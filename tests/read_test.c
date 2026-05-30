#include <criterion/criterion.h>
#include <errno.h>
#include <fcntl.h>
#include <unistd.h>

#include "libasm.h"

void	read_test(int fd, char *expected_buffer, char *actual_buffer) {
	size_t	expected_ret = read(fd, expected_buffer, 32);
	int	expected_errno = errno;
	lseek(fd, 0, SEEK_SET);
	size_t	actual_ret = ft_read(fd, actual_buffer, 32);
	int	actual_errno = errno;

	cr_assert_eq(expected_ret, actual_ret, "Return values don't match, expected %zd got %zd",
			expected_ret, actual_ret);
	cr_assert_eq(expected_errno, actual_errno, "Errno values don't match");
	//cr_assert_arr_eq(expected_buffer, actual_buffer, 32, "read content do not match");
}

Test(read_suite, regular) {
	int	fd = open("Makefile", O_RDONLY);
	char	expected_buffer[32];
	char	actual_buffer[32];


	if (fd == -1)
		cr_skip_test("Failed to open the Makefile to read it");
	read_test(fd, expected_buffer, actual_buffer);
	close(fd);
}

Test(read_suite, null_buffer) {
	int	fd = open("Makefile", O_RDONLY);

	if (fd == -1)
		cr_skip_test("Failed to open the Makefile to read it");
	read_test(fd, NULL, NULL);
	close(fd);
}
