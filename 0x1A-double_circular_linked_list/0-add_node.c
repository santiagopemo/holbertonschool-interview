#include "list.h"

/**
 * add_node_end - Add a new node to the
 * end of a double circular linked list
 * @list: A pointer to the head of the linkd list
 * @str: the string to copy into the new node
 * Return: Address of the new node, or NULL on failure
 */
List *add_node_end(List **list, char *str)
{
	List *new;

	new = malloc(sizeof(List));
	if (new == NULL)
		return (NULL);
	new->str = strdup(str);
	if (new->str == NULL)
		return (NULL);
	if ((*list) == NULL)
	{
		new->next = new;
		new->prev = new;
		(*list) = new;
		return (new);
	}
	new->next = (*list);
	new->prev = (*list)->prev;
	(*list)->prev = new;
	new->prev->next = new;
	return (new);
}

/**
 * add_node_begin - Add a new node to the
 * beginning ofa double circular linked list
 * @list: A pointer to the head of the linkd list
 * @str: the string to copy into the new node
 * Return: Address of the new node, or NULL on failure
 */
List *add_node_begin(List **list, char *str)
{
	List *new = add_node_end(list, str);

	if (new == NULL)
		return (NULL);
	(*list) = new;
	return (new);
}
