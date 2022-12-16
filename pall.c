#include "monty.h"

void pall(stack_t **stack, __attribute__((unused))unsigned int line_number)
{
	stack_t *ptr;

	if (*stack == NULL)
		return;
	ptr = *stack;
	while (ptr != NULL)
	{
		printf("%u\n", ptr->n);
		ptr = ptr->next;
	}
}
