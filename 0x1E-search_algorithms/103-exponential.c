#include "search_algos.h"

/**
 * min - function that returns the minimum of two integers
 * @a: first integer
 * @b: second integer
 *
 * Return: the minimum of a and b
 */

size_t min(size_t a, size_t b)
{
	return (a < b ? a : b);
}

/**
 * custom_binary_search - Searches for a value in a sorted array of integers
 *                        using the Binary search algorithm.
 * @array: Pointer to the first element of the array to search in.
 * @low: Starting index of the array.
 * @high: Ending index of the array.
 * @value: Value to search for.
 *
 * Return: The index where value is located,
 *         or -1 if value is not present in array.
 */

static int custom_binary_search(int *array, size_t low, size_t high, int value)
{
	size_t mid;

	while (low <= high)
	{
		size_t i;

		printf("Searching in array:");
		for (i = low; i < high; i++)
			printf(" %d,", array[i]);
		printf(" %d\n", array[i]);

		mid = (low + high) / 2;

		if (array[mid] == value)
			return (mid);
		else if (array[mid] < value)
			low = mid + 1;
		else
			high = mid - 1;
	}

	return (-1);
}

/**
 * exponential_search - searches for value in sorted array of integers ESA
 * @array: Pointer to first element of array to search in
 * @size: number of elements in array
 * @value: value to search for
 *
 * Return: first index where value is located or -1 if value
 * is not present in array or if array is NULL
 */

int exponential_search(int *array, size_t size, int value)
{
	size_t bound = 1, low, high;

	if (array == NULL || size == 0)
		return (-1);

	while (bound < size && array[bound] < value)
	{
		printf("Value checked array[%lu] = [%d]\n", bound, array[bound]);
		bound *= 2;
	}

	low = bound / 2;
	high = (bound < size ? bound : size);

	printf("Value found between indexes [%lu] and [%lu]\n", low, high - 1);

	return (custom_binary_search(array, low, high - 1, value));
}
