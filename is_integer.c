#include "monty.h"
#include <string.h>
int is_integer(char *s)
{
	int i = 0;
	int j;

	if (s == NULL)
		return (0);

	while (s[i] != '\0')
	{
		j = isdigit(s[i]);
		if (j == 0)
			return (0);
		i++;
	}
	return (1);
}
