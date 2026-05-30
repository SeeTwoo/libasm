#include <criterion/criterion.h>
#include <fcntl.h>
#include <string.h>
#include <unistd.h>
#include <errno.h>

#include "libasm.h"

#define HELLO "hello"

void	clean_files(int fd1, int fd2)
{
	if (fd1 != -1)
		close(fd1);
	if (fd2 != -1)
		close(fd2);
	unlink("testee_text");
	unlink("ref_text");
}

void	write_test(int ref_fd, int testee_fd, char *s, size_t s_len)
{
	char	ref_buffer[16] = {0};
	char	testee_buffer[16] = {0};

	size_t	ret_ref = write(ref_fd, s, s_len);
	int	errno_ref = errno;
	size_t	ret_testee = ft_write(testee_fd, s, s_len);
	int	errno_testee = errno;

	cr_assert_eq(ret_ref, ret_testee,
		"Return values don't match: expected %zd, got %zd", ret_ref, ret_testee);
	cr_assert_eq(errno_ref, errno_testee, "Errno values don't match");
	lseek(ref_fd, 0, SEEK_SET);
	lseek(testee_fd, 0, SEEK_SET);
	read(ref_fd, ref_buffer, s_len);
	read(testee_fd, testee_buffer, s_len);
	cr_assert_arr_eq(ref_buffer, testee_buffer, s_len, "File content do not match");
}

Test(write_suite, dev_full) {
	int	fd = open("/dev/full", O_RDONLY);
	char	*s = HELLO;
	size_t	s_len = strlen(s);

	if (fd == -1)
		cr_skip_test("Failed to open /dev/full");
	
	size_t	expected_ret = write(fd, s, s_len);
	int	expected_errno = errno;
	size_t	actual_ret = ft_write(fd, s, s_len);
	int	actual_errno = errno;

	cr_assert_eq(expected_ret, actual_ret,
		"Return values don't match: expected %zd, got %zd",
		expected_ret, actual_ret);
	cr_assert_eq(expected_errno, actual_errno,
		"Errno values don't match");
	close(fd);
}

Test(write_suite, regular) {
	int	ref_fd = open("ref_text", O_CREAT | O_RDWR | O_TRUNC, 0644);
	int	testee_fd = open("testee_text", O_CREAT | O_RDWR | O_TRUNC, 0644);

	if (ref_fd == -1 || testee_fd == -1) {
		clean_files(ref_fd, testee_fd);
		cr_skip_test("Failed to open temporary files");
	}
	write_test(ref_fd, testee_fd, HELLO, strlen(HELLO));
	clean_files(ref_fd, testee_fd);
}

Test(write_suite, wrong_fd_null_pointer) {
	write_test(-1, -1, NULL, 0);
}

Test(write_suite, wrong_fd) {
	write_test(-1, -1, HELLO, strlen(HELLO));
}

Test(write_suite, null_pointer) {
	int	ref_fd = open("ref_text", O_CREAT | O_RDWR | O_TRUNC, 0644);
	int	testee_fd = open("testee_text", O_CREAT | O_RDWR | O_TRUNC, 0644);

	if (ref_fd == -1 || testee_fd == -1) {
		clean_files(ref_fd, testee_fd);
		cr_skip_test("Failed to open temporary files");
	}
	write_test(ref_fd, testee_fd, NULL, 0);
	clean_files(ref_fd, testee_fd);
}
