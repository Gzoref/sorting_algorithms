#include "sort.h"
void _sort(int *arr, size_t left, size_t right);
void _merge(int *arr, size_t left, size_t mid, size_t right);
void _copy(int *arr, int *temp, size_t size);
/**
 * merge_sort - perform a merge sort
 * @array: array to sort
 * @size: size of array
 */
void merge_sort(int *array, size_t size)
{
	_sort(array, 0, size - 1);
}
/**
 * _sort - break array into sub-arrays of single elements
 * @arr: array to subdivide
 * @left: left boundary of array or sub-array
 * @right: right boundary of array or sub-array
 */
void _sort(int *arr, size_t left, size_t right)
{
	size_t mid, size = (right + 1) - left;

	/* print_array(&arr[left], (right + 1) - left); */

	if (size == 1) /* base case */
		return;

	mid = left + ((size / 2) - 1); /* calculate middle index */

	_sort(arr, left, mid);
	_sort(arr, mid + 1, right);

	_merge(arr, left, mid, right);
}
/**
 * _merge - merge sub-arrays into source array in ascending order
 * @arr: array to be sorted
 * @left: left boundary of array or sub-array
 * @mid: pivot between left and right sub-arrays (included in left)
 * @right: right boundary of array or sub-array
 */
void _merge(int *arr, size_t left, size_t mid, size_t right)
{
	size_t i_l = mid, i_r = right, j = right - left;
	int l_merged = 0, *temp = malloc(((right + 1) - left) * sizeof(int));

	printf("Merging...\n"); /* print sub-arrays */
	printf("[left]: ");
	print_array(&arr[left], (mid + 1) - left);
	printf("[right]: ");
	print_array(&arr[mid + 1], (right + 1) - (mid + 1));

	/* compare individual elements */
	for (; i_l >= left && i_r >= mid + 1;)
	{
		if (arr[i_r] >= arr[i_l])
			temp[j--] = arr[i_r--];
		else
		{
			temp[j--] = arr[i_l];
			if (i_l == 0)
			{
				l_merged = 1;
				break;
			}
			i_l--;
		}
	}
	/* merges rest of whichever sub-array isn't fully merged */
	for (; i_r >= mid + 1;)
		temp[j--] = arr[i_r--];
	for (; !l_merged && i_l >= left;)
	{
		temp[j--] = arr[i_l];
		if (i_l == 0) /* guards against size_t underflow */
			break;
		i_l--;
	}

	/* copy sorted temp back to source array */
	_copy(&arr[left], temp, (right + 1) - left);
	free(temp);

	printf("[Done]: "); /* print sorted array */
	print_array(&arr[left], (right + 1) - left);
}
/**
 * _copy - copy contents from temp array to source (same size)
 * @arr: copy destination
 * @temp: copy source
 * @size: size of arrays
 */
void _copy(int *arr, int *temp, size_t size)
{
	size_t i = 0;

	for (; i < size; i++)
		arr[i] = temp[i];
}
