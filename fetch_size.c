#include "main.h"

/**
 * fetch_size - Determines the size to cast the argument
 * @format: Formatted string in which to print the arguments
 * @index: pointer to index in format
 *
 * Return: Size.
 */
int fetch_size(const char *format, int *index)
{
	int current_index = *index + 1;
	int size = 0;

	if (format[current_index] == 'l')
		size = S_LONG;
	else if (format[current_index] == 'h')
		size = S_SHORT;

	if (size == 0)
		*index = current_index - 1;
	else
		*index = current_index;

	return (size);
}
