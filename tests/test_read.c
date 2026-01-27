#include <unistd.h>
#include <errno.h>
#include <stdio.h>
#include <string.h>
#include <fcntl.h>

#include "color.h"

ssize_t ft_read(int fd, void *buf, size_t count);

int main(void)
{
	int fd1 = open("tests/test_write.txt", O_RDONLY);
	int fd2 = open("tests/test_write.txt", O_RDONLY);
	int fde = open("", O_RDONLY);
	char buffer[1024];
	size_t count = 128;
	ssize_t ret1;
	ssize_t ret2;

	// test for ft_read()
	errno = 0;
	ret1 = ft_read(fd1, buffer, count);
	buffer[ret1] = '\0';
	printf("%s%sft_read() -> return value: %zd, errno: %d (%s), buffer: \"%s\"%s\n", BOLD, BLUE, ret1, errno, strerror(errno), buffer, END);

	//test for read()
	errno = 0;
	ret2 = read(fd2, buffer, count);
	buffer[ret2] = '\0';
	printf("%s%sread()    -> return value: %zd, errno: %d (%s), buffer: \"%s\"%s\n", BOLD, YELLOW, ret2, errno, strerror(errno), buffer, END);

	close(fd1);
	close(fd2);
	close(fde);
	return (0);
}
