#include "search_algos.h"

/*
 * linear_search - searches for value in an array of integers using Linear search algorithms
 * @array: pointer tto first element of the array to search in
 * @size: number of elements in array
 * @value: value to search for
 *
 * Retrun: the first index where value is located, or -1 if no found
 */
int linear_search(int *array, size_t size, int value)
{
	size_t i;

	if (array == NULL)
		return (-1);

	for (i = 0; i < size; i++)
	{
		printf("Value checked array[%lu] = [%d]\n", i, array[i]);
		if (array[i] == value)
			return (i);
	}

	return (-1);
}
