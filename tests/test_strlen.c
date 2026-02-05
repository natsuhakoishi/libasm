#include <stdio.h>
#include <string.h>

#include "color.h"

size_t	ft_strlen(const char *str);

int main(void)
{
	printf(BOLD LIME "<< Start Testing -> ft_strlen >>\n\n" END);

	char *str[] = {"Nijika Ijichi", "Hello World", "Lorem ipsum dolor sit amet, consectetur adipiscing elit, sed do eiusmod tempor incididunt ut labore et dolore magna aliqua. Ut enim ad minim veniam, quis nostrud exercitation ullamco laboris nisi ut aliquip ex ea commodo consequat. Duis aute irure dolor in reprehenderit in voluptate velit esse cillum dolore eu fugiat nulla pariatur. Excepteur sint occaecat cupidatat non proident, sunt in culpa qui officia deserunt mollit anim id est laborum."};

	int count = sizeof(str) / sizeof(str[0]);
	for (int i = 0; i < count; i++)
	{
		printf(BOLD LIME "Test argument %d: \"%s\"\n" END, i + 1, str[i]);
		printf(BOLD BLUE "ft_strlen()-> " END "%zu\n", ft_strlen(str[i]));
		printf(BOLD YELLOW "strlen()   -> " END "%zu\n\n", strlen(str[i]));
	}

	printf(BOLD LIME "<< End Testing -> ft_strlen >>\n" END);
	return (0);
}
