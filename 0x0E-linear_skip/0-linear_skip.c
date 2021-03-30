#include "search.h"

/**
 * linear_skip - function that searches for a value in
 * an array of integers using the jump search
 * @list: Pointer to the first element of the list to search in
 * @value: Value to search for
 * Return: A pointer on the first node where value is located,
 * otherwise NULL
 */
skiplist_t *linear_skip(skiplist_t *list, int value)
{
	skiplist_t *last, *current;

	if (list == NULL)
		return (NULL);
	for (last = current = list; current->next != NULL && current->n < value;)
	{
		last = current;
		if (current->express == NULL)
		{
			for (; current->next != NULL; current = current->next)
				continue;
			break;
		}
		current = current->express;
		printf("Value checked at index [%lu] = [%d]\n",
			   current->index, current->n);
	}
	printf("Value found between indexes [%lu] and [%lu]\n",
			last->index, current->index);
	current = last;
	for (; current != NULL && current->n <= value; current = current->next)
	{
		printf("Value checked at index [%lu] = [%d]\n",
				current->index, current->n);
		if (current->n == value)
			return (current);
	}
	return (NULL);
}
