#include "monty.h"
#include <string.h>
int is_integer(char *s)
{
	int i = 0;
	int j;
	int negative_flag = 0;

	if (s == NULL)
		return (0);

	if (s[0] == '-')
	{
		negative_flag = 1;
		i++;
	}
	while (s[i] != '\0')
	{
		j = isdigit(s[i]);
		if (j == 0)
			return(0);
		i++;
	}
	if (negative_flag == 1)
		return(2);
	return(1);
}
