#include "main.h"

/**
 * clear_bit - Sets a bit to 0.
 *
 * @num: The number.
 * @index: The position to set the bit.
 *
 * Description: Sets 1 bit to 0.
 *
 * Return: 1 if successful, -1 if failed.
 */
int clear_bit(unsigned long int *num, unsigned int index)
{
	if (index > 64)
		return (-1);

	*num &= ~(1ul << index);

	return (1);
}
