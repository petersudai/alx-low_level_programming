#include "lists.h"

/**
 * pop_listint - deletes the head node of a listint_t
 * @head: double pointer
 *
 * Return: head node’s data (n), or 0 if list is empty
 */

int pop_listint(listint_t **head)
{
	int data = 0;
	listint_t *temp;

	if (*head != NULL)
	{
		temp = *head;
		data = temp->n;
		*head = (*head)->next;
		free(temp);
	}

	return (data);
}
