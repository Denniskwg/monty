#include "monty.h"

int search(char *str)
{
	int i = 0;
	int j = 0;
	char *opcodes[] = {"pint", "pall", "pop", "swap", "add", NULL};

	while (opcodes[i] != NULL)
	{
		if (strcmp(opcodes[i], str) == 0)
		{
			j = 1;
			break;
		}
		i++;
	}
	return(j);
}
