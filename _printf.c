#include <stddef.h>
#include "main.h"
#include <stdarg.h>

/**
 * _printf - produces output according to a format
 * @format: a character string containing zero or more directives
 *
 * Return: the number of characters printed (excluding the null byte used to
 * end output to strings)
 */
int _printf(const char *format, ...)
{
    int count = 0;
    va_list args;
    int (*printer)(va_list);

    va_start(args, format);

    while (*format)
    {
        if (*format == '%')
        {
            format++;
            printer = NULL;

            if (*format == '\0')
                break;

            if (*format == '%')
                printer = &print_percent;
            else if (*format == 'c')
                printer = &print_char;
            else if (*format == 's')
                printer = &print_string;
            else if (*format == 'd' || *format == 'i')
                printer = &print_int;
            else if (*format == 'b')
                printer = &print_binary;
            else if (*format == 'u')
                printer = &print_unsigned_int;
            else if (*format == 'o')
                printer = &print_octal;
            else if (*format == 'x' || *format == 'X')
                printer = &print_hex;
            else if (*format == 'p')
                printer = &print_pointer;
            else if (*format == 'r')
                printer = &print_reversed;
            else if (*format == 'S')
                printer = &print_non_printable;

            if (printer != NULL)
                count += printer(args);
            else
            {
                _putchar('%');
                _putchar(*format);
                count += 2;
            }
        }
        else
        {
            _putchar(*format);
            count++;
        }

        format++;
    }

    va_end(args);

    return (count);
}
