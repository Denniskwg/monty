#include "monty.h"

void free_av(char **array)
{
	int i;

	for (i = 0; array[i]; i++)
		free(array[i]);
	free(array);
}

void free_stack(stack_t *stack)
{
	stack_t *ptr, *next;

	ptr = stack;
	while (ptr != NULL)
	{
		next = ptr->next;
		free(ptr);
		ptr = next;
	}
}
