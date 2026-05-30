#include <stdio.h>
#include <errno.h>
#include <string.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

#include "libasm.h"

int	main(int ac, char **av)
{
	if (ac != 1) {
		puts("args youu moron\n");
		return 1;
	}
	(void)av;

	char	*s = "hello";
//	char	*dup = ft_strdup(s);
	char	*dup = strdup(s);
	if (!dup)
		return 1;
	printf("%s\n", dup);
	free(dup);
	return 0;
}
