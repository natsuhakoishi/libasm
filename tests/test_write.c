#include <unistd.h>
#include <errno.h>
#include <stdio.h>
#include <string.h>

#include "color.h"

ssize_t ft_write(int fd, const char *buf, size_t count);

void pmsg(char *str)
{
	printf("%s%s<< Start Testing -> ft_write >>%s\n\n", BOLD, LIME, END);
	printf("%s%sTest argument: \"%s\"%s\n", BOLD, LIME, str, END);
}

int main(void)
{
	int fd = 1;
	char *str = "Nijika Ijichi";
	size_t count = strlen(str) + 1;
	ssize_t ret1;
	ssize_t ret2;

	pmsg(str);

	// test for ft_write()
	errno = 0;
	ret1 = ft_write(fd, str, count);
	printf("\n%s%sft_write() -> return value: %zd, errno: %d (%s)%s\n", BOLD, BLUE, ret1, errno, strerror(errno), END);

	//test for write()
	errno = 0;
	ret2 = write(fd, str, count);
	printf("\n%s%swrite()    -> return value: %zd, errno: %d (%s)%s\n\n", BOLD, YELLOW, ret2, errno, strerror(errno), END);

	printf(BOLD LIME "<< End Testing -> ft_write >>\n" END);
	return (0);
}
