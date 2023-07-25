#include <stdarg.h>
#include "main.h"
#include <stddef.h>
/**
 * _printf - prints a formatted string to stdout
 * @format: the format string
 * Return: the number of characters printed, or (-1) on failure
 */
int _printf(const char *format, ...)
{
	va_list args;
	int i, count = 0;

	if (format == NULL)
		return (-1);

	va_start(args, format);

	for (i = 0; format[i] != '\0'; i++)
	{
		if (format[i] == '%')
		{
			i++;
			if (format[i] == '\0')
				return (-1);
			else if (format[i] == ' ')
				return (-1);
			else if (format[i] == '\\')
				return (-1);

			switch (format[i])
			{
				case 'c':
					count += print_char(args);
					break;
				case 's':
					count += print_string(args);
					break;
				case 'd':
				case 'i':
					count += print_int(args);
					break;
				case 'u':
					count += print_unsigned_int(args);
					break;
				case 'o':
					count += print_octal(args);
					break;
				case 'x':
				case 'X':
					count += print_hex(args);
					break;
				case 'p':
					count += print_pointer(args);
					break;
				case '%':
					count += print_percent(args);
					break;
				default:
					_putchar('%');
					_putchar(format[i]);
					count += 2;
					break;
			}
		}
		else
		{
			_putchar(format[i]);
			count++;
		}
	}

	va_end(args);

	return (count);
}
