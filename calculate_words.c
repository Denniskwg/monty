#include "monty.h"

int calculate_words(char *str)
{
	int i = 0, words = 0;

	while (str[i] != '\0')
	{
		if (str[i] == ' ')
			words++;
		i++;
	}
	return (words);
}
