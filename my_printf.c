#include "main.h"
#include <stdarg.h>

/**
 * _printf - an implentation for printf function
 *
 * @format: a character string
 *
 * Return: number of characters printed
 */


int _printf(const char *format, ...)
{
	va_list args;

	va_start(args, format);

	int len = 0;

	while (*format != '\0')
	{
		if (*format == '%')
		{
			format++;
			if (*format == '%')
			{
				_putchar('%');
				len++;
			}
			else if (*format == 'c')
			{
				char c = va_arg(args, int);
				_putchar(c);
				len++;
			}
			else if (*format == 's')
			{
				char *s = va_arg(args, char*);
				while (*s != '\0') {
					_putchar(*s);
					s++;
					len++;
				}
			}
		}
		else
		{
			_putchar(*format);
			len++;
		}

		format++;
	}
	va_end(args);

	return (len);
}
