#include <stdio.h>
#include <string.h>
#include <errno.h>

#include "color.h"

char *ft_strdup(const char *s);

int main(void)
{
	printf(BOLD LIME "<< Start Testing -> ft_strdup >>\n\n" END);

	char *str[] = {"Nijika Ijichi", "Hello World", "Lorem ipsum dolor sit amet, consectetur adipiscing elit, sed do eiusmod tempor incididunt ut labore et dolore magna aliqua. Ut enim ad minim veniam, quis nostrud exercitation ullamco laboris nisi ut aliquip ex ea commodo consequat. Duis aute irure dolor in reprehenderit in voluptate velit esse cillum dolore eu fugiat nulla pariatur. Excepteur sint occaecat cupidatat non proident, sunt in culpa qui officia deserunt mollit anim id est laborum."};

	int count = sizeof(str) / sizeof(str[0]);
	for (int i = 0; i < count; i++)
	{
		char *test_ft;
		char *test_lib;

		printf("%s%sTest argument %d: \"%s\"%s\n", BOLD, LIME, i + 1, str[i], END);

		errno = 0;
		test_ft = ft_strdup(str[i]);
		printf("%s%sft_strdup() ->%s %s%s errno: %d (%s) %s\n", BOLD, BLUE, END, test_ft, BLUE, errno, strerror(errno), END);

		errno = 0;
		test_lib = strdup(str[i]);
		printf("%s%sstrdup()    ->%s %s%s errno: %d (%s) %s\n", BOLD, YELLOW, END, test_lib, YELLOW, errno, strerror(errno), END);

		int diff = strcmp(test_ft, test_lib);
		if (diff == 0)
			printf(BOLD LIME "diff: OK\n\n" END);
		else
			printf(BOLD RED "diff: KO, %d\n\n" END, diff);
	}

	printf(BOLD LIME "<< End Testing -> ft_strdup >>\n" END);
	return (0);
}
