#include "monty.h"

void pall(stack_t **stack, unsigned int line_number)
{
	stack_t *ptr;

	if (*stack == NULL)
		return;
	ptr = *stack;
	while (line_number != 1)
	{
		printf("%u\n", ptr->n);
		ptr = ptr->next;
		line_number--;
	}
}
