#include "main.h"
#include <stddef.h>
#include <stdarg.h>
/**
 * print_char - prints a char
 * @arg: argument containing the char to print
 * Return: the number of characters printed
 */
int print_char(va_list arg)
{
	char c = va_arg(arg, int);

	_putchar(c);
	return (1);
}

/**
 * print_string - prints a string
 * @arg: argument containing the char to print
 * Return: the number of characters printed
 */
int print_string(va_list arg)
{
	char *s = va_arg(arg, char *);
	int count = 0;

	if (s == NULL)
	{
		s = "(null)";
	}
	while (*s)
	{
		_putchar(*s);
		count++;
		s++;
	}

	return (count);
}

/**
 * print_percent - prints a percent sign
 * @arg: unused
 * Return: the number of characters printed
 */
int print_percent(va_list arg)
{
	(void)arg;
	_putchar('%');
	return (1);
}

/**
 * print_reversed - prints a reversed string
 * @arg: the argument containing the string to reverse and print
 * Return: the number of characters printed
 */
int print_reversed(va_list arg)
{
	char *s = va_arg(arg, char *);
	int count = 0;
	int length = 0;
	int i;

	while (s[length] != '\0')
		length++;

	for (i = length - 1; i >= 0; i--)
	{
		_putchar(s[i]);
		count++;
	}

	return (count);
}

/**
 * print_non_printable - prints a string, replacing non-printable characters
 *					  with their ASCII codes in hexadecimal
 * @arg: argument containing the string to print
 * Return: the number of characters printed
 */
int print_non_printable(va_list arg)
{
	char *s = va_arg(arg, char *);
	int count = 0;

	if (s == NULL)
	{
		s = "(null)";
	}

	while (*s)
	{
		if (*s < 32 || *s >= 127)
		{
			_putchar('\\');
			_putchar('x');
			count += 2;
			count += print_hex(arg);
		}
		else
		{
			_putchar(*s);
			count++;
		}

		s++;
	}

	return (count);
}
