#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "color.h"

char *ft_strcpy(char *dst, const char *src);

int main(void)
{
	char *str = "Nijika Ijichi";
	char *dest = malloc(strlen(str) + 1);

	printf(BOLD LIME "Test argument(s): \"%s\"\n" END, str);
	printf(BOLD BLUE "ft_strcpy()-> " END "%s\n", ft_strcpy(dest, str));
	printf(BOLD YELLOW "strcpy()   -> " END "%s\n", strcpy(dest, str));

	free(dest);
	return (0);
}
