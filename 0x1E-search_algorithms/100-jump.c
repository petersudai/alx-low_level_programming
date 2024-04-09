#include "search_algos.h"

/**
 * jump_search - Searches for value in a sorted array of integers
 * @array: Pointer to first element of array to search in
 * @size: no. of elements in the array
 * @value: value to search for
 *
 * Return: first index where value is located, or -1 if not present or NULL
 */

int jump_search(int *array, size_t size, int value)
{
	size_t step, prev, next;

	step = sqrt(size);
	prev = 0;
	next = 0;

	if (array == NULL || size == 0)
		return (-1);

	while (array[prev] < value && next < size)
	{
		printf("Value checked array[%lu] =[%d]\n", next, array[next]);
		prev = next;
		next += step;
		if (next >= size)
			break;
	}

	printf("Value found between indexes [%lu] and [%lu]\n", prev, next);

	while(prev <= next && prev < size)
	{
		printf("Value checked array[%lu] = [%d]\n", prev, array[prev]);
		
		if (array[prev] == value)
			return (prev);
		prev++;
	}
	return (-1);
}
