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
	count += print_binary(va_arg(arg, unsigned int));

	_putchar(n % 2 + '0');
	count++;

	return (count);
}

/**
 * print_hex - prints an unsigned integer converted to hexadecimal
 * @arg: the argument containing the unsigned integer to print
 * @uppercase: whether to use uppercase letters for the hexadecimal digits
 * Return: the number of characters printed
 */
int print_hex(va_list arg, int uppercase)
{
	unsigned int n = va_arg(arg, unsigned int);
	int count = 0;
	char hex_digits[16] = "0123456789abcdef";
	int base = 16;

	if (uppercase)
		hex_digits[10] = 'A', hex_digits[11] = 'B',
		hex_digits[12] = 'C', hex_digits[13] = 'D',
		hex_digits[14] = 'E', hex_digits[15] = 'F';

	if (n / base)
		count += print_hex(va_arg(arg, unsigned int), uppercase);

	_putchar(hex_digits[n % base]);
	count++;

	return (count);
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
		count += print_octal(va_arg(arg, unsigned int));

	_putchar(n % 8 + '0');
	count++;

	return (count);
}
