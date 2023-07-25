#include <stddef.h>
#include "main.h"
#include <stdarg.h>
/**
 * print_binary - prints an unsigned integer converted to binary
 * @arg: the argument containing the unsigned integer to print
 * Return: the number of characters printed
 */
int print_binary(va_list arg)
{
	unsigned int n = va_arg(arg, unsigned int);
	int count = 0;

	if (n / 2)
	count += print_binary(arg);

	_putchar(n % 2 + '0');
	count++;

	return (count);
}

/**
 * print_hex - prints an unsigned int in hexadecimal format
 * @args: the va_list containing the unsigned int to print
 *
 * Return: the number of characters printed
 */
int print_hex(va_list args)
{
	unsigned int n = va_arg(args, unsigned int);
	int count = 0;

	if (n / 16)
		count += print_hex(args);

	if (n % 16 < 10)
		_putchar(n % 16 + '0');
	else
		_putchar(n % 16 - 10 + 'a');

	count++;

	return count;
}

/**
 * print_octal - prints an unsigned integer converted to octal
 * @arg: the argument containing the unsigned integer to print
 * Return: the number of characters printed
 */
int print_octal(va_list arg)
{
	unsigned int n = va_arg(arg, unsigned int);
	int count = 0;

	if (n / 8)
		count += print_octal(arg);

	_putchar(n % 8 + '0');
	count++;

	return (count);
}
