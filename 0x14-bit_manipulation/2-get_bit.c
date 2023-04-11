#include "main.h"

/**
 * get_bit - Returns the value of a bit at a given index.
 *
 * @num: The number to evaluate.
 * @idx: The index of the bit we want to get (starting from 0).
 *
 * Return: The value of the bit at the given index, or -1 if an error occurs.
 */

int get_bit(unsigned long int num, unsigned int idx)
{
	if (idx >= sizeof(unsigned long int) * 8)
		return (-1);

	return ((num >> idx) & 1);
}
