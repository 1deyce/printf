#include "main.h"

void show_buffer_content(char content[], int *content_index);

/**
 * custom_printf - Custom print function
 * @format: format.
 * Return: Count of printed characters.
 */
int _printf(const char *format, ...)
{
	int index, printed = 0, total_printed_chars = 0;
	int flags, width, precision, size, content_index = 0;
	va_list args;
	char content[BUFFER_CAPACITY];

	if (format == NULL)
		return (-1);

	va_start(args, format);

	for (index = 0; format && format[index] != '\0'; index++)
	{
		if (format[index] != '%')
		{
			content[content_index++] = format[index];
			if (content_index == BUFFER_CAPACITY)
				show_buffer_content(content, &content_index);

			total_printed_chars++;
		}
		else
		{
			show_buffer_content(content, &content_index);
			flags = fetch_flags(format, &index);
			width = fetch_width(format, &index, args);
			precision = fetch_precision(format, &index, args);
			size = fetch_size(format, &index);
			++index;
			printed = process_format(format, &index, args, content,
				flags, width, precision, size);
			if (printed == -1)
				return (-1);
			total_printed_chars += printed;
		}
	}

	show_buffer_content(content, &content_index);

	va_end(args);

	return (total_printed_chars);
}

/**
 * show_buffer_content - Displays the contents of the buffer if they exist
 * @content: Array of characters
 * @content_index: Index at which to add next character, represents the length.
 */
void show_buffer_content(char content[], int *content_index)
{
	if (*content_index > 0)
		write(1, &content[0], *content_index);

	*content_index = 0;
}
