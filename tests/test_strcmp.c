#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "color.h"

int ft_strcmp(const char *s1, const char *s2);

int main(void)
{
	printf(BOLD LIME "<< Testing -> ft_strcmp >>\n\n" END);

	char *s1[] = {"Nijika Ijichi", "zzz", "assembly", "compare"};
	char *s2[] = {"Nijika Ijichi", "abc", "assemble", "compare"};

	int count = sizeof(s1) / sizeof(s1[0]);
	for (int i = 0; i < count; i++)
	{
		printf(BOLD LIME "Test argument %d - \"%s\" | " END, i + 1, s1[i]);
		printf(BOLD LIME "\"%s\"\n" END, s2[i]);

		printf(BOLD BLUE "ft_strcmp()-> " END "%d\n", ft_strcmp(s1[i], s2[i]));
		printf(BOLD YELLOW "strcmp()   -> " END "%d\n\n", strcmp(s1[i], s2[i]));
	}

	printf(BOLD LIME "<< End Testing -> ft_strcmp >>\n" END);
	return (0);
}
