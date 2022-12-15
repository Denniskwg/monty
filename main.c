#include "monty.h"
int number = 0;
int main(int ac, char **av)
{
	FILE *ptr;
	char **strings = malloc(size * sizeof(char *));
	char *code, *num;
	int i = 0, j;
	size_t n = 0;
	unsigned int line_number = 0;
	stack_t *stack = NULL;

	strings[size - 1] = NULL;
	if (ac == 1 || ac > 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
	ptr = fopen(av[1], "r");
	if (ptr == NULL)
	{
		strtok(av[1], "/");
		fprintf(stderr, "Error: Can't open file %s\n", strtok(NULL, "/"));
		exit(EXIT_FAILURE);
	}
	while ((getline(&strings[i], &n, ptr)) != -1)
	{
		line_number++;
		j = strlen(strings[i]);
		strings[i][j - 1] = '\0';
		if (strlen(strings[i]) == 0)
		{
			line_number--;
			continue;
		}
		if (calculate_words(strings[i]) == 0 && (strcmp(strings[i], "push") != 0))
			match_opcode(strings[i], &stack, line_number);
		else
		{
			code = strtok(strings[i], " ");
			num = strtok(NULL, " ");
			if (is_integer(num))
			{
				number = atoi(num);
				match_opcode(code, &stack, line_number);
			}
			else
			{
				fprintf(stderr, "L%d: usage: push integer\n", line_number);
				exit(EXIT_FAILURE);
			}
		}
		i++;
	}
	fclose(ptr);
	free_av(strings);
	free_stack(&stack);
	return (0);
}

void push(stack_t **stack, __attribute__((unused))unsigned int line_number)
{
	stack_t *temp;

	temp = malloc(sizeof(stack_t));
	if (temp == NULL)
	{
		fprintf(stderr, "Error: malloc failed");
		exit(EXIT_FAILURE);
	}
	temp->n = number;
	if (*stack == NULL)
	{
		temp->prev = NULL;
		temp->next = NULL;
		*stack = temp;
	}
	(*stack)->prev = temp;
	temp->next = *stack;
	*stack = temp;
}
