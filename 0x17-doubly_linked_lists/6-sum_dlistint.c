#include "lists.h"

/**
 * sum_dlistint - returns sum of all data of a dlistint_t list
 * @head: pointer to head of doubly linked list
 *
 * Return: sum of all data values in linked list. if list is empty return 0
 */

int sum_dlistint(dlistint_t *head)
{
	int sum = 0;

	while (head != NULL)
	{
		sum += head->n;
		head = head->next;
	}

	return (sum);
}
