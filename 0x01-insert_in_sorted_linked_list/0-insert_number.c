#include "lists.h"

/**
 * insert_node - inserts a number into a sorted singly linked list
 * @head: pointer to head of list
 * @number: number to insert in list
 * Return: The address of the new node, or NULL if it failed
 */
listint_t *insert_node(listint_t **head, int number)
{
	listint_t *tmp;
	listint_t *new;

	new = malloc(sizeof(listint_t));
	if (new == NULL)
		return (NULL);
	new->n = number;
	if (*head == NULL || number < (*head)->n)
	{
		new->next = *head;
		*head = new;
		return (new);
	}
	for (tmp = *head; tmp->next != NULL; tmp = tmp->next)
	{
		if (number >= tmp->n && number < tmp->next->n)
		{
			new->next = tmp->next;
			tmp->next = new;
			return (new);
		}
	}
	tmp->next = new;
	new->next = NULL;
	return (new);
}
