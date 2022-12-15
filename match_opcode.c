#include "monty.h"
#include <stdlib.h>

void match_opcode(char *str, stack_t **stack, unsigned int line_number)
{
	instruction_t instructions[size] = {
		{"push", push},
		{"pall", pall},
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
			exit(EXIT_FAILURE);
		}
	}
}
