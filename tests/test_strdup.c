#include <stdio.h>
#include <string.h>
#include <errno.h>

#include "color.h"

char *ft_strdup(const char *s);

int main(void)
{
	char *str = "Nijika Ijichi";

	char *test_ft;
	char *test_lib;

	printf("%s%sTest argument(s): \"%s\"%s\n", BOLD, LIME, str, END);

	errno = 0;
	test_ft = ft_strdup(str);
	printf("%s%sft_strdup() -> return string: %s, errno: %d (%s)%s\n", BOLD, BLUE, test_ft, errno, strerror(errno), END);

	errno = 0;
	test_lib = strdup(str);
	printf("%s%sstrdup()    -> return string: %s, errno: %d (%s)%s\n", BOLD, YELLOW, test_lib, errno, strerror(errno), END);
	return (0);
}
