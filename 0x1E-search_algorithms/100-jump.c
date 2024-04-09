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
	size_t step, prev;

	step = sqrt(size);
	prev = 0;

	if (array == NULL || size == 0)
		return (-1);

	while (array[prev] < value)
	{
		printf("Value checked array[%lu] =[%d]\n", prev, array[prev]);
		prev += step;
		if (prev >= size)
			break;
	}
	printf("Value found between indexes [%lu] and [%lu]\n", prev - step, prev);

	prev -= step;
	while(array[prev] < value)
	{
		printf("Value checked array[%lu] = [%d]\n", prev, array[prev]);
		prev++;
		if (prev == size)
			return (-1);
	}

	printf("Value checked array[%lu] = [%d}\n", prev, array[prev]);
	if (array[prev] == value)
		return (prev);
	return (-1);
}
