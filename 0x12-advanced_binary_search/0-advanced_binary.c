#include "search_algos.h"

/**
 * recursive_binary_search - function that searches for a value in
 * an array of integers using the Binary search
 * @array: Pointer to the first element of the array to search in
 * @low: low position in array
 * @high: high position in array
 * @value: Value to search for
 * @r: pointer to resul variable
 * Return: if value is not present in array or if array
 * is NULL, your function the function return -1
 */
void recursive_binary_search(int *array, int low, int high, int value, int *r)
{
	int i, middle;

	if (high < low)
		return;
	printf("Searching in array: ");
	for (i = low; i < high; i++)
		printf("%d, ", array[i]);
	printf("%d\n", array[i]);
	middle = low + (high - low) / 2;
	if (array[middle] == value && array[middle - 1] != value)
		*r = middle;
	else if (array[middle] >= value)
		recursive_binary_search(array, low, middle, value, r);
	else
		recursive_binary_search(array, middle + 1, high, value, r);
}
/**
 * advanced_binary - function that searches for a value in
 * an array of integers using the Linear search
 * @array: Pointer to the first element of the array to search in
 * @size: Is the number of elements in array
 * @value: Value to search for
 * Return: if value is not present in array or if array
 * is NULL, your function the function return -1
 */
int advanced_binary(int *array, size_t size, int value)
{
	int result = -1;

	if (array == NULL)
		return (-1);
	recursive_binary_search(array, 0, (int)size - 1, value, &result);
	return (result);
}
