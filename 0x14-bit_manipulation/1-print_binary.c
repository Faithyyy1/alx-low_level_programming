#include "main.h"

/**
 * _power - calculate the result of raising base to the power of pow
 * @base: the base of the exponent
 * @exponent: the power of the exponent
 * Return: the result of base raised to the power of exponent
 */
unsigned long int _power(unsigned int base, unsigned int exponent)
{
	unsigned long int result = 1;
	unsigned int i;

	for (i = 0; i < exponent; i++)
	{
		result *= base;
	}
	return (result);
}

/**
 * print_binary - prints the binary representation of a number
 * @num: the number to be printed in binary
 * Return: void
 */
void print_binary(unsigned long int num)
{
	unsigned long int mask = _power(2, sizeof(unsigned long int) * 8 - 1);
	char flag = 0;

	while (mask > 0)
	{
		/* Check if the current bit is set */
		if ((num & mask) == mask)
		{
			/* If it is set, print a '1' and set the flag */
			_putchar('1');
			flag = 1;
		}
		else if (flag == 1 || mask == 1)
		{
			/* If the flag is set or we've reached the last bit, print a '0' */
			_putchar('0');
		}

		/* Shift the mask one bit to the right */
		mask >>= 1;
	}
}
