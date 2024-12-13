#include <stdio.h>
#include "sort.h"

/**
 * bubble_sort - sorts an array of integers in ascending order
 * using the bubble sort algorithm
 * @array: array of integer to be sorted
 * @size: size of array
*/

void bubble_sort(int *array, size_t size)
{
	size_t i, j, temp;

	temp = 0;

	for (i = 0; i < size - 1; i++)
	{
		for (j = 0; j < size - 1 - i; j++)
		{
			if (array[j] > array[j + 1])
			{
				temp = array[j];
				array[j] = array[j + 1];
				array[j + 1] = temp;
				print_array(array, size);
			}
		}
	}
}
