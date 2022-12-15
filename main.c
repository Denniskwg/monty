#include "monty.h"
int number = 0;
int main(int ac, char **av)
{
	FILE *ptr;
	char *code, *num, *string;
	int i = 0, j, k;
	size_t n = 0;
	unsigned int line_number = 0;
	stack_t *stack = NULL;

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
	while ((getline(&string, &n, ptr)) != -1)
	{
		line_number++;
		j = strlen(string);
		string[j - 1] = '\0';
		if (strlen(string) == 0)
		{
			line_number--;
			continue;
		}
		if (calculate_words(string) == 0 && (strcmp(string, "push") != 0))
			match_opcode(string, &stack, line_number, ptr);
		else
		{
			code = strtok(string, " ");
			num = strtok(NULL, " ");
			k = is_integer(num);
			if (k)
			{
				number = atoi(num);
				match_opcode(code, &stack, line_number, ptr);
			}
			else
			{
				fprintf(stderr, "L%d: usage: push integer\n", line_number);
				free(string);
				free_stack(stack);
				fclose(ptr);
				exit(EXIT_FAILURE);
			}
		}
		free(string);
		string = NULL;
		i++;
	}
	fclose(ptr);
	free(string);
	free_stack(stack);
	return (0);
}

void push(stack_t **stack, __attribute__((unused))unsigned int line_number)
{
	stack_t *temp;

	temp = malloc(sizeof(stack_t));
	if (temp == NULL)
	{
		fprintf(stderr, "Error: malloc failed");
		free_stack(*stack);
		exit(EXIT_FAILURE);
	}
	temp->n = number;
	if (*stack == NULL)
	{
		temp->prev = NULL;
		temp->next = NULL;
		*stack = temp;
	}
	else
	{
		(*stack)->prev = temp;
		temp->next = *stack;
		*stack = temp;
	}
}
