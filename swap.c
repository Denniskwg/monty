#include "monty.h"

void swap(stack_t **stack, unsigned int line_number)
{
	int i = 0;
	stack_t *ptr;

	ptr = *stack;
	while (ptr != NULL)
	{
		i++;
		ptr = ptr->next;
	}
	if (i < 2)
	{
		fprintf(stderr, "L%u: can't swap, stack too short\n", line_number);
		free_stack(*stack);
		exit(EXIT_FAILURE);
	}
	ptr = (*stack)->next;
	i = (*stack)->n;
	(*stack)->n = ptr->n;
	ptr->n = i;
}
