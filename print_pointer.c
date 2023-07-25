#include "main.h"

/**
 * print_pointer - prints a pointer address to stdout
 * @arg: the argument containing the pointer to print
 * Return: the number of characters printed
 */
int print_pointer(va_list arg)
{
	void *p = va_arg(arg, void *);
	int count = 0;

	_putchar('0');
	_putchar('x');
	count += 2;

	count += print_hex((va_list)&p, 0);

	return (count);
}

