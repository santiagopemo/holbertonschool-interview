#include "lists.h"

/**
 * check_cycle - function that checks if a singly linked list has a cycle in it
 * @list: pointer to head of list
 * Return: 0 if there is no cycle, 1 if there is a cycle
 */
int check_cycle(listint_t *list)
{
	listint_t *hare, *turttle;

	for (hare = turttle = list; hare != NULL; hare = hare->next)
	{
		hare = hare->next;
		if (hare == turttle)
			return (1);
		if (hare == NULL)
			return (0);
		turttle = turttle->next;
	}
	return (0);
}
