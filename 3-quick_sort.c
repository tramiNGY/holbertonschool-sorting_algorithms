#include "sort.h"

/**
 * swap - swap values
 * @a: first value to swap
 * @b: second value to swap
 */
void swap(int *a, int *b)
{
	int temp;

	temp = *a;
	*a = *b;
	*b = temp;
}

/**
 * quicksort_partition - sets a pivot at last element and swap values
 * @array: array of integers
 * @size: size of the array
 * @left: start of unsorted array
 * @right: ending of unsorted array
 * Return: the final index of the partition
 */
int quicksort_partition(int *array, size_t size, int left, int right)
{
	int *pivot, big, small;

	pivot = array + right;
	for (big = small = left; small < right; small++)
	{
		if (array[small] < *pivot)
		{
			if (big < small)
			{
				swap(array + small, array + big);
				print_array(array, size);
			}
			big++;
		}
	}
	if (array[big] > *pivot)
	{
		swap(array + big, pivot);
		print_array(array, size);
	}
	return (big);
}

/**
 * quicksort_rec - sorts through recursion
 * @array: array to be sorted
 * @size: size of the array
 * @left: start of the unsorted array
 * @right: end of the unsorted array
 */

void quicksort_rec(int *array, size_t size, int left, int right)
{
	int part;

	if (right - left > 0)
	{
		part = quicksort_partition(array, size, left, right);
		quicksort_rec(array, size, left, part - 1);
		quicksort_rec(array, size, part + 1, right);
	}
}

/**
 * quick_sort - sort an array of integer in an ascending order
 * @array: array of integer
 * @size: size of the array
 */

void quick_sort(int *array, size_t size)
{
	if (array == NULL || size < 2)
		return;
	quicksort_rec(array, size, 0, size - 1);
}
