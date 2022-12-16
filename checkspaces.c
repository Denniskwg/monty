#include "monty.h"

/**
 * check_spaces - checks if a string only contains
 * white spaces
 * @str: string to check
 * Return: 0 if string only contains white spaces
 * 1 if string contains other characters
 */
int check_spaces(char *str)
{
	int i = 0;
	int j = 0;

	while (str[j] != '\0')
	{
		if (str[j] != ' ')
		{
			i = 1;
			break;
		}
		j++;
	}
	return(i);
}
