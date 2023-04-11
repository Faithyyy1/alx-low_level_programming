#include "main.h"

/**
 * set_bit - Sets the value of a bit to 1 at a given index.
 *
 * @num_ptr: A pointer to the number to modify.
 * @idx: The index of the bit to set (starting from 0).
 *
 * Return: 1 if successful, or -1 if an error occurred.
 */

int set_bit(unsigned long int *num_ptr, unsigned int idx)
{
	/*
	 * Check if the index is greater
	 * than the number of bits in unsigned long int.
	 *
	 */

	if (idx > (sizeof(unsigned long int) * 8 - 1))
		return (-1);

	*num_ptr |= (1 << idx);
	return (1);
}
