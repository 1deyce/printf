#include "main.h"

/**
 * is_char_printable - Evaluates if a char is printable
 * @c: Char to be evaluated.
 *
 * Return: 1 if c is printable, 0 otherwise
 */
int is_char_printable(char c)
{
	if (c >= 32 && c < 127)
		return (1);

	return (0);
}

/**
 * append_hexadecimal_code - Append ASCII in hexadecimal code to buffer
 * @buffer: Array of chars.
 * @i: Index at which to start appending.
 * @ascii_code: ASCII CODE.
 * Return: Always 3
 */
int append_hexadecimal_code(char ascii_code, char buffer[], int i)
{
	char map_to[] = "0123456789ABCDEF";
	/* The hexadecimal format code is always 2 digits long */
	if (ascii_code < 0)
		ascii_code *= -1;

	buffer[i++] = '\\';
	buffer[i++] = 'x';

	buffer[i++] = map_to[ascii_code / 16];
	buffer[i] = map_to[ascii_code % 16];

	return (3);
}

/**
 * is_char_digit - Verifies if a char is a digit
 * @c: Char to be evaluated
 *
 * Return: 1 if c is a digit, 0 otherwise
 */
int is_char_digit(char c)
{
	if (c >= '0' && c <= '9')
		return (1);

	return (0);
}

/**
 * cast_number_to_size - Casts a number to the specified size
 * @num: Number to be casted.
 * @size: Number indicating the type to be casted.
 *
 * Return: Casted value of num
 */
long int cast_number_to_size(long int num, int size)
{
	if (size == S_LONG)
		return (num);
	else if (size == S_SHORT)
		return ((short)num);

	return ((int)num);
}

/**
 * cast_unsigned_to_size - Casts a number to the specified size
 * @num: Number to be casted
 * @size: Number indicating the type to be casted
 *
 * Return: Casted value of num
 */
long int cast_unsigned_to_size(unsigned long int num, int size)
{
	if (size == S_LONG)
		return (num);
	else if (size == S_SHORT)
		return ((unsigned short)num);

	return ((unsigned int)num);
}

int print_char() {
    UNUSED(flags);
    UNUSED(width);
    UNUSED(precision);
    UNUSED(size);
    char c = (char)va_arg(types, int);
    buffer[0] = c;
    return 1;
}

int print_string() {
    UNUSED(flags);
    UNUSED(width);
    UNUSED(precision);
    UNUSED(size);
    char *str = va_arg(types, char*);
    int i = 0;
    while(str[i] != '\0' && i < BUFFER_SIZE - 1) {
        buffer[i] = str[i];
        i++;
    }
    buffer[i] = '\0';
    return i;
}

int print_percent() {
    UNUSED(types);
    UNUSED(flags);
    UNUSED(width);
    UNUSED(precision);
    UNUSED(size);
    buffer[0] = '%';
    return 1;
}

int print_int() {
    UNUSED(flags);
    UNUSED(width);
    UNUSED(precision);
    UNUSED(size);
    int num = va_arg(types, int);
    return sprintf(buffer, "%d", num);
}

int print_binary() {
    UNUSED(flags);
    UNUSED(width);
    UNUSED(precision);
    UNUSED(size);
    int num = va_arg(types, int);
    int i, count = 0;
    for (i = sizeof(num) * 8 - 1; i >= 0; i--) {
        buffer[count++] = (num & (1 << i)) ? '1' : '0';
    }
    return count;
}

int print_unsigned() {
    UNUSED(flags);
    UNUSED(width);
    UNUSED(precision);
    UNUSED(size);
    unsigned int num = va_arg(types, unsigned int);
    return sprintf(buffer, "%u", num);
}

int print_octal() {
    UNUSED(flags);
    UNUSED(width);
    UNUSED(precision);
    UNUSED(size);
    unsigned int num = va_arg(types, unsigned int);
    return sprintf(buffer, "%o", num);
}

int print_hexadecimal() {
    UNUSED(flags);
    UNUSED(width);
    UNUSED(precision);
    UNUSED(size);
    unsigned int num = va_arg(types, unsigned int);
    return sprintf(buffer, "%x", num);
}

int print_hexa_upper() {
    UNUSED(flags);
    UNUSED(width);
    UNUSED(precision);
    UNUSED(size);
    unsigned int num = va_arg(types, unsigned int);
    return sprintf(buffer, "%X", num);
}

int print_non_printable() {
    return 0;
}

int print_pointer() {
    UNUSED(flags);
    UNUSED(width);
    UNUSED(precision);
    UNUSED(size);
    void *ptr = va_arg(types, void*);
    return sprintf(buffer, "%p", ptr);
}

int print_reverse() {
    return 0;
}

int print_rot13string() {
    return 0;
}

int is_printable(char c) {
    return (c >= 32 && c <= 126);
}

int append_hexa_code(char c, char buffer[], int index) {
    return sprintf(buffer + index, "\\x%02X", c);
}

int is_digit(char c) {
    return (c >= '0' && c <= '9');
}

long int convert_size_number(long int num, int size) {
    return num;
}

long int convert_size_unsgnd(unsigned long int num, int size) {
    return num;
}
