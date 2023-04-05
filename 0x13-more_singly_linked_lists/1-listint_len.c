#include <stdlib.h>
#include "lists.h"

/**
 * listint_len - Prints the number of elements in a linked listint_t list
 * @h: integer
 * Return: Pointer to the head node of the linked list
 *
 * Description: singly linked list node structure
 */
size_t listint_len(const listint_t *h);
{
	while (h)
	{
		h = h->next;
		num_of_nodes++;
	}

	return (num_of_nodes);
}
