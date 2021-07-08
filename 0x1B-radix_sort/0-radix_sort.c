#include "sort.h"

/**
 * largest - return the largerst element in array
 * @array: array to sort
 * @size: size of the array to sort
 * Return: the largest number in array
 */
int largest(int *array, size_t size)
{
	size_t i;
	int max = array[0];

	for (i = 1; i < size; i++)
	{
		if (array[i] > max)
			max = array[i];
	}
	return (max);
}

/**
 * counting_sort - function that sorts an array of integers
 * in ascending order using the Counting sort algorithm
 * @array: array to sort
 * @size: size of the array to sort
 * @key: the key digit according to the base for sort the array
 */
void counting_sort(int *array, int size, int key)
{
	int *output = NULL;
		int i = 0;
		int count[10] = {0};

		output = malloc(sizeof(int) * size);
		if (output == NULL)
			return;
		for (i = 0; i < size; i++)
			count[(array[i] / key) % 10]++;
		for (i = 1; i < 10; i++)
			count[i] += count[i - 1];

		for (i = size - 1; i >= 0; i--)
		{
			output[count[(array[i] / key) % 10] - 1] = array[i];
			count[(array[i] / key) % 10]--;
		}

		for (i = 0; i < size; i++)
			array[i] = output[i];

		free(output);
		print_array(array, size);
}

/**
 * radix_sort - function that sorts an array of integers
 * in ascending order using the Radix sort algorithm
 * @array: array to sort
 * @size: array size
 */
void radix_sort(int *array, size_t size)
{
	int base, max, i;

	if (array == NULL && size <= 1)
		return;
	max = largest(array, size);
	for (i = 1, base = 10; max / i > 0; i *= base)
	{
		counting_sort(array, size, i);
	}
}
