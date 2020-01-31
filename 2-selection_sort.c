#include "sort.h"

/**
 * selection_sort - Selection sort algorithm
 * @array: The array to be sorted
 * @size: Size of the array
 * Return: Void
 */
void selection_sort(int *array, size_t size)
{

	size_t counter1, counter2;
	int min_index, temp_swap;

	for (counter1 = 0; counter1 < size - 1; counter1++)
	{
		min_index = counter1;
		for (counter2 = counter1 + 1; counter2 < size; counter2++)
		{
			if(array[counter2] < array[min_index])
			{
				min_index = counter2;
			}
			temp_swap = array[min_index];
			array[counter2] = array[min_index];
 			array[counter2] = temp_swap;
			print_array(array, size);
		}
	}

}
