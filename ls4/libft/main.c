#include <stdio.h>
#include "libft.h"

int		main(void)
{
	char *str;

	str = ft_strdup("test");
	printf("%s\n", str);
	free(str);
	return (0);
}
