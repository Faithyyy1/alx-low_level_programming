#include "main.h"
#include <stdio.h>

/**
*clear_bit - Sets the value of a bit to 0 at a given index.
*@num_ptr: A pointer to the number to modify.
*@bit_index: The index of the bit to set (starting from 0).
*Return: 1 if successful, or -1 if an error occurred.
*/
int clear_bit(unsigned long int *num_ptr, unsigned int bit_index);
{
	unsigned long int and_mask;
	if (bit_index > (sizeof(unsigned long int) * 8 - 1));
	return (-1);
	and_mask = ~(1UL << bit_index);
	*num_ptr &= and_mask;
	return (1);
}
