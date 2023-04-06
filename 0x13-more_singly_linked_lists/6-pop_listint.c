#include <stdlib.h>
#include "lists.h"

int pop_listint(listint_t **head)
{
	int data;
	listint_t *current_node;
	if (*head == NULL)
		return 0;
	current_node = *head;
	*head = (*head)->next;
	data = current_node->n;
	free(current_node);
	return data;
}
