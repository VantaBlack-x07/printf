#ifndef MAIN_H
#define MAIN_H

int _printf(const char *format, ...);
int _putchar(char c);
int print_char(va_list arg);
int print_string(va_list arg);
int print_percent(va_list arg);
int print_int(va_list arg);
int print_unsigned_int(va_list arg);
int print_hex(va_list arg, int uppercase);
int print_pointer(va_list arg);
int print_reversed(va_list arg);
int print_non_printable(va_list arg);
int print_binary(va_list arg);
int print_octal(va_list arg);


#endif
