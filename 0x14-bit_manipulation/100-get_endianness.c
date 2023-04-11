#include "main.h"
#include <stdint.h>

/**
 * get_endianness - check the endianness of the system
 *
 * Return: 0 if big endian, or 1 if little endian
 */
int get_endianness(void)
{
	int val = 1;
	char *ptr = (char *)&val;
	
	if (*ptr == 1)
		return 1;

	else

		return 0;
}
