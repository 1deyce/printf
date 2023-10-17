#include "main.h"

/**
 * fetch_flags - Computes active flags
 * @format: Formatted string in which to print the arguments
 * @index: pointer to index in format
 * Return: Flags:
 */
int fetch_flags(const char *format, int *index)
{
	/* - + 0 # ' ' */
	/* 1 2 4 8  16 */
	int flag_index, current_index;
	int active_flags = 0;
	const char FLAG_CHARS[] = {'-', '+', '0', '#', ' ', '\0'};
	const int FLAG_VALUES[] = {F_MINUS, F_PLUS, F_ZERO, F_HASH, F_SPACE, 0};

	for (current_index = *index + 1; format[current_index] != '\0'; current_index++)
	{
		for (flag_index = 0; FLAG_CHARS[flag_index] != '\0'; flag_index++)
			if (format[current_index] == FLAG_CHARS[flag_index])
			{
				active_flags |= FLAG_VALUES[flag_index];
				break;
			}

		if (FLAG_CHARS[flag_index] == 0)
			break;
	}

	*index = current_index - 1;

	return (active_flags);
}
