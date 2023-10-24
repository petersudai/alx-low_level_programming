#include "lists.h"

/**
 * free_listint_safe - frees a listint_t linked list safely
 * @h: double pointer to the head of the list
 *
 * Return: size of the list thats freed
 */

size_t free_listint_safe(listint_t **h)
{
	listint_t *slow, *fast, *temp;
	size_t count = 0;

	slow = *h;
	fast = *h;

	while (fast && fast->next)
	{
		temp = slow;
		slow = slow->next;
		fast = fast->next->next;
		free(temp);

		if (slow == fast)
		{
			*h = NULL;
			return (++count);
		}
		count++;
	}

	while (slow)
	{
		temp = slow;
		slow = slow->next;
		free(temp);
		count++;
	}
	*h = NULL;
	return (count);
}
