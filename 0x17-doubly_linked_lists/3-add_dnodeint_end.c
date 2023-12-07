#include "lists.h"

/**
 * add_dnodeint_end - adds new node at end of a dlistint_t list
 * @head: pointer to pointer of the head of the doubly linked list
 * @n: integer value to be assigned to the new node
 *
 * Return: address of new element, or NULL if failed
 */

dlistint_t *add_dnodeint_end(dlistint_t **head, const int n)
{
	dlistint_t *new_node;
	dlistint_t *last_node;

	if (head == NULL)
		return (NULL);

	new_node = malloc(sizeof(dlistint_t));
	if (new_node == NULL)
		return (NULL);

	new_node->n = n;
	new_node->next = NULL;

	if (*head == NULL)
	{
		new_node->prev = NULL;
		*head = new_node;
		return (new_node);
	}

	last_node = *head;
	while (last_node->next != NULL)
		last_node = last_node->next;

	new_node->prev = last_node;
	last_node->next = new_node;

	return (new_node);
}
