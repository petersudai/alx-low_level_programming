#include "lists.h"

/**
 * free_listint2 - frees a listint_t lists and sets the head to NULL
 * @head: pointer to pointer of head of list
 *
 * Return: void
 */

void free_listint2(listint_t **head)
{
	listint_t *temp;

	while (*head != NULL)
	{
		temp = *head;
		*head = (*head)->next;
		free(temp);
	}
}
