#include "monty.h"
#include <stdlib.h>

void match_opcode(char *str, stack_t **stack, unsigned int line_number, FILE *ptr)
{
	instruction_t instructions[size] = {
		{"push", push},
		{"pall", pall},
		{"pint", pint},
		{"pop", pop},
		{"swap", swap},
		{NULL, NULL}
	};
	int k = 0;

	while (instructions[k].opcode != NULL)
	{
		if (strcmp(str, instructions[k].opcode) == 0)
		{
			instructions[k].f(stack, line_number);
			break;
		}
		k++;
		if (instructions[k].opcode == NULL)
		{
			fprintf(stderr, "L%d: unknown instruction %s\n", line_number, str);
			free_stack(*stack);
			free(str);
			fclose(ptr);
			exit(EXIT_FAILURE);
		}
	}
}
