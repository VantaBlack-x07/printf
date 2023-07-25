#ifndef PRINT_CHARACTERS_H
#define PRINT_CHARACTERS_H

#include "main.h"

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
	int i;

	if (s == NULL)
		s = "(null)";

	for (i = 0; s[i]; i++)

	for (i -= 1; i >= 0; i--)
	{
		_putchar(s[i]);
		count++;
	}

	return (count);
}

/**
 * print_non_printable - prints non-printable characters
 * with their ASCII code
 * @arg: the argument containing the string to print
 * Return: the number of characters printed
 */
int print_non_printable(va_list arg)
{
	char *s = va_arg(arg, char *);
	int count = 0;

	if (s == NULL)
		s = "(null)";

	while (*s)
	{
		if (*s < 32 || *s >= 127)
		{
			_putchar('\\');
			_putchar('x');
			count += 2;
			count += print_hex((va_list)s, 1);
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

#endif /* PRINT_CHARACTERS_H */
