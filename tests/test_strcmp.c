#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "color.h"

int ft_strcmp(const char *s1, const char *s2);

int main(void)
{
	char *s1 = "Nijika Ijichi";
	char *s2 = "Nijika Ijichi";

	printf(BOLD LIME "Test argument - char *s1 = \"%s\"\n" END, s1);
	printf(BOLD LIME "Test argument - char *s2 = \"%s\"\n" END, s2);

	printf(BOLD BLUE "ft_strcmp()-> " END "%d\n", ft_strcmp(s1, s2));
	printf(BOLD YELLOW "strcmp()   -> " END "%d\n", strcmp(s1, s2));

	return (0);
}
