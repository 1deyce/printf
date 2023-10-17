#include "main.h"
#include <stdint.h>  /* For uintmax_t */
#include <stddef.h>  /* For ptrdiff_t */

long int convert_size_number(long int num, int size);
long int convert_size_unsgnd(long int num, int size) {
    switch (size) {
        case 'h': /* short */
            return (unsigned short)num;
        case 'l': /* long */
            return (unsigned long)num;
        case 'j': /* intmax_t or uintmax_t */
            return (uintmax_t)num;
        case 'z': /* size_t */
            return (size_t)num;
        case 't': /* ptrdiff_t */
            return (ptrdiff_t)num;
        default:  /* int, or anything else */
            return (unsigned int)num;
    }
}

int hexadecimal_converter(va_list types, char map_to[], char buffer[],
	int flags, char flag_ch, int width, int precision, int size);

/************************* UNSIGNED NUMBER OUTPUT *************************/
int unsigned_number_output(va_list types, char buffer[],
	int flags, int width, int precision, int size)
{
	int i = BUFF_SIZE - 2;
	long int num = va_arg(types, long int);

	num = convert_size_unsgnd(num, size);

	if (num == 0)
		buffer[i--] = '0';

	buffer[BUFF_SIZE - 1] = '\0';

	while (num > 0)
	{
		buffer[i--] = (num % 10) + '0';
		num /= 10;
	}

	i++;

	return (write_unsgnd(0, i, buffer, flags, width, precision, size));
}

/************************* OCTAL NUMBER OUTPUT *************************/
int octal_number_output(va_list types, char buffer[],
	int flags, int width, int precision, int size)
{
	int i = BUFF_SIZE - 2;
	long int num = va_arg(types, long int);
	long int init_num = num;

	UNUSED(width);

	num = convert_size_unsgnd(num, size);

	if (num == 0)
		buffer[i--] = '0';

	buffer[BUFF_SIZE - 1] = '\0';

	while (num > 0)
	{
		buffer[i--] = (num % 8) + '0';
		num /= 8;
	}

	if (flags & F_HASH && init_num != 0)
		buffer[i--] = '0';

	i++;

	return (write_unsgnd(0, i, buffer, flags, width, precision, size));
}

/************************* HEXADECIMAL OUTPUT *************************/
int hexadecimal_output(va_list types, char buffer[],
	int flags, int width, int precision, int size)
{
	return (hexadecimal_converter(types, "0123456789abcdef", buffer,
		flags, 'x', width, precision, size));
}

/***************** UPPER CASE HEXADECIMAL OUTPUT *****************/
int uppercase_hexadecimal_output(va_list types, char buffer[],
	int flags, int width, int precision, int size)
{
	return (hexadecimal_converter(types, "0123456789ABCDEF", buffer,
		flags, 'X', width, precision, size));
}

/***************** HEXADECIMAL CONVERTER *****************/
int hexadecimal_converter(va_list types, char map_to[], char buffer[],
	int flags, char flag_ch, int width, int precision, int size)
{
	int i = BUFF_SIZE - 2;
	long int num = va_arg(types, long int);
	long int init_num = num;

	UNUSED(width);

	num = convert_size_unsgnd(num, size);

	if (num == 0)
		buffer[i--] = '0';

	buffer[BUFF_SIZE - 1] = '\0';

	while (num > 0)
	{
		buffer[i--] = map_to[num % 16];
		num /= 16;
	}

	if (flags & F_HASH && init_num != 0)
	{
		buffer[i--] = flag_ch;
		buffer[i--] = '0';
	}

	i++;

	return (write_unsgnd(0, i, buffer, flags, width, precision, size));
}
