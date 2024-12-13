#include "sort.h"
#include <stdio.h>
#include <stddef.h>

/**
 * selection_sort - search the smallest int in the array
 * and move it to the bottom of the unsorted array
 * @array: array of integer
 * @size: size of the array
 */

void selection_sort(int *array, size_t size)
{
	size_t i, j, min, temp;

	temp = 0;

	for (i = 0; i < size; i++)
	{
		min = i;

		for (j = i + 1; j < size; j++)
		{
			if (array[j] < array[min])
				min = j;
		}
		if (min != i)
		{
			temp = array[i];
			array[i] = array[min];
			array[min] = temp;
			print_array(array, size);
		}
	}
}
