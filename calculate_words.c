#include "monty.h"

int calculate_words(char *str, char delim)
{
	int i = 0, words = 0;

	while (str[i] != '\0')
	{
		if (str[i] == delim)
			words++;
		i++;
	}
	return (words);
}
