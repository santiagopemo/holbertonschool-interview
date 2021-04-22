#include "sort.h"

/**
 * idx_parent - return the parent of a index in a hepified array
 * @idx: the index
 * Return: the parent index
 */
size_t idx_parent(int idx)
{
	return (2 * idx + 1);
}
/**
 * swap - swap two elements in a array
 * @array: pointer to the array
 * @size: the array's size
 * @a_idx: the index of the first element
 * @b_idx: the index of the second element
 */
void swap(int *array, size_t size, int a_idx, int b_idx)
{
	int tmp = array[a_idx];

	array[a_idx] = array[b_idx];
	array[b_idx] = tmp;
	print_array(array, size);
}

/**
 * shift_down - Repair the heap whose root element is at index start
 * @array: pointer to the array
 * @size: the array's size
 * @start: heap's root index in array
 * @end: heap's final child index in array
 */
void shift_down(int *array, size_t size, size_t start, size_t end)
{
	size_t root = start;
	size_t child;
	size_t swap_idx;

	for (; idx_parent(root) <= end;)
	{
		child = idx_parent(root);
		swap_idx = root;

		if (array[swap_idx] < array[child])
			swap_idx = child;
		if (child + 1 <= end && array[swap_idx] < array[child + 1])
			swap_idx = child + 1;
		if (swap_idx == root)
			return;
		swap(array, size, root, swap_idx);
		root = swap_idx;
	}
}

/**
 * heapify - orders elements in array like a heap
 * @array: pointer to array
 * @size: array's size
 */
void heapify(int *array, int size)
{
	int start = ((size - 2) / 2);

	for (; start >= 0; start--)
	{
		shift_down(array, size, start, size - 1);
	}
}
/**
 * heap_sort - function that sorts an array of integers
 * in ascending order using the Heap sort algorithm
 * @array: the array
 * @size: the array's size
 */
void heap_sort(int *array, size_t size)
{
	int end;

	heapify(array, size);
	for (end = size - 1; end > 0; )
	{
		swap(array, size, end, 0);
		end--;
		shift_down(array, size, 0, end);
	}
}
