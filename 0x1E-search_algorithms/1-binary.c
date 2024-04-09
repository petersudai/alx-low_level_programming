#include "search_algos.h"

/**
 * binary_search - searches for a value in sorted array of integers using BSA
 * @array: pointer to first element of array to search in
 * @size: number of elements in array
 * @value: value to search for
 *
 * Retrun: index where value is located or -1 if not found
 */
int binary_search(int *array, size_t size, int value)
{
	size_t left = 0, right = size - 1, mid, i;

	if (array == NULL)
		return (-1);

	while (left <= right)
	{
		printf("Searching in array:");
		for (i = left; i < right; i++)
			printf(" %d,", array[i]);
		printf(" %d\n", array[i]);

		mid = (left + right) / 2;

		if (array[mid] < value)
			left = mid + 1;
		else if (array[mid] > value)
			right = mid - 1;
		else
			return (mid);
	}

	return (-1);
}
