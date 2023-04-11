#include "main.h"
#include <stdio.h>

/**
 * binary_to_uint - converts a binary number to an unsigned int
 * @binary: pointer to string of 0 and 1 chars
 *
 * Return: the converted number, or 0 if there is one or more
 * chars in the string binary that is not 0 or 1, or binary is NULL
 */
unsigned int binary_to_uint(const char *binary)
{
	unsigned int result = 0;

	if (binary == NULL)
		return (0);

	for (; *binary != '\0'; binary++)
	{
		if (*binary == '0')
			result = (result << 1);
		else if (*binary == '1')
			result = (result << 1) | 1;
		else
			return (0);
	}

	return (result);
}

