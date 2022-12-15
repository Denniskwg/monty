#include "monty.h"

void free_av(char **array)
{
	int i;

	for (i = 0; array[i]; i++ )
		free( array[i] );
	free(array);
}

void free_stack(stack_t **stack)
{
	stack_t *ptr;

	if (*stack == NULL)
		return;
	ptr = *stack;
	while (ptr != NULL && ptr->next)
	{
		*stack = ptr->next;
		free(ptr->prev);
		free(ptr);
		ptr = (*stack)->next;
	}
	free(stack);
}
