#include "lists.h"

/**
 * find_listint_loop - function that finds the loop in a linked list
 *  @head: linked list head
 * Returns: The address of the node where the loop starts,
 * or NULL if there is no loop
 */
listint_t *find_listint_loop(listint_t *head)
{
    listint_t *i, *j;

    for (i = j = head; j && j->next;)
    {
		i = i->next;
		j = j->next->next;

		if (i == j)
		{
			for (i = head; i != j; i = i->next, j = j->next)
				continue;
			return (i);
		}
    }
	return(NULL);
}
