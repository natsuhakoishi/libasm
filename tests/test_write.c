#include <unistd.h>
#include <errno.h>
#include <stdio.h>
#include <string.h>

#include "color.h"

ssize_t ft_write(int fd, const char *buf, size_t count);

int main(void)
{
	int fd = 1;
	char *str = "Nijika Ijichi";
	size_t count = 14;
	ssize_t ret1;
	ssize_t ret2;

	// test for ft_write()
	errno = 0;
	printf("%s%s <- ft_write() output %s", BOLD, BLUE, END);
	ret1 = ft_write(fd, str, count);
	printf("\n%s%sft_write() -> return value: %zd, errno: %d (%s)%s\n", BOLD, BLUE, ret1, errno, strerror(errno), END);

	printf("\n");

	//test for write()
	errno = 0;
	printf("%s%s <- write() output  %s", BOLD, YELLOW, END);
	ret2 = write(fd, str, count);
	printf("\n%s%swrite()    -> return value: %zd, errno: %d (%s)%s\n", BOLD, YELLOW, ret2, errno, strerror(errno), END);

	return (0);
}
