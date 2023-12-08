#include "lists.h"

/**
 * delete_dnodeint_at_index - deletes node at index
 * @head: double pointer to head of list
 * @index: index of node to delete, starting from 0
 *
 * Return: 1 successful, -1 failed
 */

int delete_dnodeint_at_index(dlistint_t **head, unsigned int index)
{
	dlistint_t *current, *temp;
	unsigned int i = 0;

	if (*head == NULL)
		return (-1);

	current = *head;

	if (index == 0)
	{
		*head = current->next;
		if (*head != NULL)
			(*head)->prev = NULL;
		free(current);
		return (-1);
	}

	while (i < index && current != NULL)
	{
		current = current->next;
		i++;
	}

	if (current == NULL)
		return (-1);

	temp = current->prev;
	temp->next = current->next;

	if (current->next != NULL)
		current->next->prev = temp;

	free(current);

	return (1);
}
