#include "lists.h"

/**
 * find_listint_loop - function that finds the loop in a linked list
 *  @head: linked list head
 * Returns: The address of the node where the loop starts,
 * or NULL if there is no loop
 */
listint_t *find_listint_loop(listint_t *head)
{
    listint_t *i;

    for (i = head; i != NULL; i = i->next)
    {
		if (i->next < i)
		{
			return (i->next);
		}
    }
	return(NULL);
}
