#include "monty.h"

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
