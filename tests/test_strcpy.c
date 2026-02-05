#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "color.h"

char *ft_strcpy(char *dst, const char *src);

int main(void)
{
	printf(BOLD LIME "<< Start Testing -> ft_strcpy >>\n\n" END);

	char *str[] = {"Nijika Ijichi", "Hello World", "Lorem ipsum dolor sit amet, consectetur adipiscing elit, sed do eiusmod tempor incididunt ut labore et dolore magna aliqua. Ut enim ad minim veniam, quis nostrud exercitation ullamco laboris nisi ut aliquip ex ea commodo consequat. Duis aute irure dolor in reprehenderit in voluptate velit esse cillum dolore eu fugiat nulla pariatur. Excepteur sint occaecat cupidatat non proident, sunt in culpa qui officia deserunt mollit anim id est laborum."};

	int count = sizeof(str) / sizeof(str[0]);
	for (int i = 0; i < count; i++)
	{
		char *dst_test = malloc(strlen(str[i]) + 1);
		char *dst_lib = malloc(strlen(str[i]) + 1);

		printf(BOLD LIME "Test argument %d: \"%s\"\n" END, i + 1, str[i]);
		printf(BOLD BLUE "ft_strcpy()-> " END "%s\n", ft_strcpy(dst_test, str[i]));
		printf(BOLD YELLOW "strcpy()   -> " END "%s\n", strcpy(dst_lib, str[i]));
		int diff = strcmp(dst_test, dst_lib);
		if (diff == 0)
			printf(BOLD LIME "diff: OK\n\n" END);
		else
			printf(BOLD RED "diff: KO, %d\n\n" END, diff);

		free(dst_test);
		free(dst_lib);
	}

	printf(BOLD LIME "<< End Testing -> ft_strcpy >>\n" END);
	return (0);
}
