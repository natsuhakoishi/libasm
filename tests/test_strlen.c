#include <stdio.h>
#include <string.h>

#include "color.h"

size_t	ft_strlen(const char *str);

int main(void)
{
	char *str = "Nijika Ijichi";

	printf(BOLD LIME "Test argument(s): \"%s\"\n" END, str);
	printf(BOLD BLUE "ft_strlen()-> " END "%zu\n", ft_strlen(str));
	printf(BOLD YELLOW "strlen()   -> " END "%zu\n", strlen(str));
	return (0);
}
