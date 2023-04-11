#include "main.h"
#include <stdio.h>

/**
 * flip_bits - Returns the number of bits you would need to flip to get one number to another.
 * @num1: The first number.
 * @num2: The second number.
 *
 * Return: The number of bits that differ between the two numbers.
 */
unsigned int flip_bits(unsigned long int num1, unsigned long int num2)
{
	unsigned long int xor_result;
	int num_flips;
	
	xor_result = num1 ^ num2;
	num_flips = 0;
	
	while (xor_result != 0)
   {
	   num_flips += (xor_result & 1);
	   xor_result >>= 1;
   }
	return num_flips;
}
