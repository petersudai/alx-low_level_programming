#include "lists.h"

/**
 * sum_listint - returns sum of all data (n) of a listint_t linked list
 * @head: pointer to head of  the list
 *
 * Return: sum of all list data or 0 if empty
 */

int sum_listint(listint_t *head)
{
	int sum = 0;

	while (head != NULL)
	{
		sum += head->n;
		head = head->next;
	}

	return (sum);
}
