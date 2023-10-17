#include "main.h"

/**
 * fetch_width - Determines the width for printing
 * @format: Formatted string in which to print the arguments.
 * @index: pointer to index in format
 * @args: list of arguments.
 *
 * Return: width.
 */
int fetch_width(const char *format, int *index, va_list args)
{
	int current_index;
	int width = 0;

	for (current_index = *index + 1; format[current_index] != '\0'; current_index++)
	{
		if (is_digit(format[current_index]))
		{
			width *= 10;
			width += format[current_index] - '0';
		}
		else if (format[current_index] == '*')
		{
			current_index++;
			width = va_arg(args, int);
			break;
		}
		else
			break;
	}

	*index = current_index - 1;

	return (width);
}