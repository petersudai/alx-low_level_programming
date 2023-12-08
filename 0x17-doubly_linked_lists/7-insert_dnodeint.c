#include "lists.h"

/**
 * create_dnodeint - create new doubly linked list node
 * @n: data for new node
 * Return: address of new_node or NULL if fail
 */
dlistint_t *create_dnodeint(int n)
{
	dlistint_t *new_node;

	new_node = malloc(sizeof(dlistint_t));

	if (!new_node)
		return (NULL);

	new_node->n = n;
	new_node->prev = NULL;
	new_node->next = NULL;

	return (new_node);
}

/**
 * insert_dnodeint_at_index - inserts a new node at a given position
 * @h: pointer to address of head of doubly linked list
 * @idx: index where the new node should be added.
 * @n: value to be stored in new node
 *
 * Return: address of new node, NULL if it failed.
 */

dlistint_t *insert_dnodeint_at_index(dlistint_t **h, unsigned int idx, int n)
{
	dlistint_t *new_node, *current;
	unsigned int i;

	if (!h)
		return (NULL);

	new_node = create_dnodeint(n);

	if (!new_node)
		return (NULL);

	if (idx == 0)
	{
		new_node->next = *h;
		if (*h)
			(*h)->prev = new_node;
		*h = new_node;
		return (new_node);
	}

	current = *h;

	for (i = 0; current && i < idx - 1; ++i)
		current = current->next;

	if (!current)
	{
		free(new_node);
		return (NULL);
	}


	new_node->next = current->next;
	new_node->prev = current;
	if (current->next)
		current->next->prev = new_node;
	current->next = new_node;

	return (new_node);
}
