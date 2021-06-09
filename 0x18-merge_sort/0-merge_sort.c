#include "sort.h"

/**
 * my_print_array - prints an array
 * @array: the array
 * @i_begin: initial array's index
 * @i_end: final array's index
 */
void my_print_array(int *array, size_t i_begin, size_t i_end)
{
	size_t i;

	for (i = i_begin; i < i_end; i++)
	{
		if (i > i_begin)
			printf(", ");
		printf("%d", array[i]);
	}
	printf("\n");
}

/**
 * copy_array - copies a array
 * @array: the array to be copied
 * @size: the array size
 * Return: pointer to the new array, NULL if fails
 */
int *copy_array(int *array, size_t size)
{
	int *new_array, i;

	if (array == NULL)
		return (NULL);
	new_array = malloc(sizeof(int) * size);
	for (i = 0; i < (int)size; i++)
	{
		new_array[i] = array[i];
	}
	return (new_array);
}

/**
 * top_dow_merge - splits the array to sort
 * @array_a: auxiliar array
 * @array_b: array to be sort
 * @i_begin: initial index of the piece of the array to be sorted
 * @i_end: initial index of the piece of the array to be sorted
 * @i_middle: index in the middle of the piece of the array to be sorted
 */
void top_dow_merge(int *array_a, int *array_b, int i_begin,
									int i_end, int i_middle)
{
	int i, j, k;

	printf("Merging...\n");
	printf("[left]: ");
	my_print_array(array_a, i_begin, i_middle);
	printf("[right]: ");
	my_print_array(array_a, i_middle, i_end);
	for (i = k = i_begin, j = i_middle; k < i_end; k++)
	{
		if (i < i_middle && (j >= i_end || array_a[i] <= array_a[j]))
		{
			array_b[k] = array_a[i];
			i++;
		}
		else
		{
			array_b[k] = array_a[j];
			j++;
		}
	}
	printf("[Done]: ");
	my_print_array(array_b, i_begin, i_end);
}

/**
 * top_down_split_merge - splits the array to sort
 * @array_a: auxiliar array
 * @array_b: array to be sort
 * @i_begin: initial index of the piece of the array to be splited
 * @i_end: initial index of the piece of the array to be splited
 */
void top_down_split_merge(int *array_a, int *array_b, int i_begin, int i_end)
{
	int i_middle;

	if (i_end - i_begin <= 1)
		return;
	i_middle = (i_end + i_begin) / 2;
	top_down_split_merge(array_b, array_a, i_begin, i_middle);
	top_down_split_merge(array_b, array_a, i_middle, i_end);
	top_dow_merge(array_a, array_b, i_begin, i_end, i_middle);
}

/**
 * merge_sort - function that sorts an array of integers
 * in ascending order using the Merge Sort algorithm
 * @array: pointer to the array to sort
 * @size: size of the array
 */
void merge_sort(int *array, size_t size)
{
	int *array_b = copy_array(array, size);

	if (array_b == NULL)
		return;

	top_down_split_merge(array_b, array, 0, size);
	free(array_b);
}
