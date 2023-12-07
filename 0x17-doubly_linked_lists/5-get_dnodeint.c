#include "lists.h"

/**
 * get_dnodeint_at_index - returns  the nth node of dlistint_t list
 * @head: pointer to hed of doubly linked list
 * @index: index of node to retrieve
 *
 * Return: pointer to nth node, or NULL if node is non-existent
 */

dlistint_t *get_dnodeint_at_index(dlistint_t *head, unsigned int index)
{
	unsigned int i = 0;

	while (head != NULL)
	{
		if (i == index)
			return (head);
		head = head->next;
		i++;
	}

	return (NULL);
}
