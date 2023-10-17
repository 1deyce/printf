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


int is_printable(char c) {
    return (c >= 32 && c <= 126);
}

void append_hexa_code(char* str, char c) {
    sprintf(str, "%02X", c);
}

int convert_size_number(int num) {
    return num;
}

void print_char(char c) {
    putchar(c);
}

void print_string(char *s) {
    if(s != NULL) {
        printf("%s", s);
    }
}

void print_percent() {
    printf("%%");
}

void print_int(int i) {
    printf("%d", i);
}

void print_binary(int num) {
    for (int i = 31; i >= 0; i--) {
        putchar((num & (1 << i)) ? '1' : '0');
    }
}

void print_unsigned(unsigned int num) {
    printf("%u", num);
}

void print_octal(int num) {
    printf("%o", num);
}

void print_hexadecimal(int num) {
    printf("%x", num);
}

void print_hexa_upper(int num) {
    printf("%X", num);
}

void print_pointer(void *p) {
    printf("%p", p);
}

void print_non_printable(char *s) {
    while (*s) {
        if (is_printable(*s)) {
            putchar(*s);
        } else {
            printf("\\x%02X", *s);
        }
        s++;
    }
}

void print_reverse(char *s) {
    int len = strlen(s);
    for (int i = len - 1; i >= 0; i--) {
        putchar(s[i]);
    }
}

void print_rot13string(char *s) {
    while (*s) {
        if ((*s >= 'A' && *s <= 'M') || (*s >= 'a' && *s <= 'm')) {
            putchar(*s + 13);
        } else if ((*s >= 'N' && *s <= 'Z') || (*s >= 'n' && *s <= 'z')) {
            putchar(*s - 13);
        } else {
            putchar(*s);
        }
        s++;
    }
}