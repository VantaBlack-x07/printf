#include <stddef.h>
#include "main.h"
#include <stdarg.h>
/**
 * print_int - prints an integer
 * @arg: the argument containing the integer to print
 * Return: the number of characters printed
 */
int print_int(va_list arg)
{
	int n = va_arg(arg, int);
	int count = 0;
	int sign = 1;

	if (n < 0)
	{
		sign = -1;
		n = -n;
		_putchar('-');
		count++;
	}
	if (n / 10)
	{
		count += print_int(arg);
	}
	_putchar(n % 10 * sign + '0');
	count++;

	return (count);
}

/**
 * print_unsigned_int - prints an unsigned integer
 * @arg: the argument containing the unsigned integer to print
 * Return: the number of characters printed
 */
int print_unsigned_int(va_list arg)
{
	unsigned int n = va_arg(arg, unsigned int);
	char buffer[100];
	int count = 0;
	int i;

	if (n == 0)
	{
		_putchar('0');
		return (1);
	}

	for (i = 0; n > 0; i++)
	{
		buffer[i] = (n % 10) + '0';
		n /= 10;
	}

	count += i;

	for (i -= 1; i >= 0; i--)
		_putchar(buffer[i]);

	return (count);
}
