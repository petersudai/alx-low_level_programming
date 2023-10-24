#include "lists.h"

/**
 * delete_nodeint_at_index - deletes node at index index of a listint_t list
 * @head: double pointer to head of list
 * @index: index of node to be deleted
 *
 * Return: 1 if succeeded, -1 if failed
 */

int delete_nodeint_at_index(listint_t **head, unsigned int index)
{
	listint_t *temp, *prev;
	unsigned int i;

	if (*head == NULL)
		return (-1);

	if (index == 0)
	{
		temp = *head;
		*head = (*head)->next;
		free(temp);
		return (1);
	}

	prev = *head;
	temp = prev->next;

	for (i = 1 ; i < index && temp != NULL ; i++)
	{
		prev = temp;
		temp = temp->next;
	}

	if (temp == NULL)
		return (-1);

	prev->next = temp->next;
	free(temp);

	return (-1);
}
