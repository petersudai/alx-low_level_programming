#include "lists.h"

/**
 * get_nodeint_at_index - returns the nth node of a listint_t linked list.
 * @head: pointer to head of list
 * @index: index of node
 *
 * Return: a pointer to the nth node, or NULL otherwise
 */

listint_t *get_nodeint_at_index(listint_t *head, unsigned int index)
{
	unsigned int i;

	for (i = 0 ; i < index && head != NULL ; i++)
	{
		head = head->next;
	}
	return (head);
}
