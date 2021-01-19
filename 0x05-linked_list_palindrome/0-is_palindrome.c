#include "lists.h"

/**
 * is_palindrome_recursion - function that checks if a singly is a palindrome
 * @h: double pointer to head of list
 * @tmp: pointer to travel the list recursively
 * Return: 0 if it is not a palindrome, 1 if it is a palindrome
 */
int is_palindrome_recursion(listint_t **h, listint_t *tmp)
{
	int res;

	if (tmp == NULL)
		return (1);
	res = is_palindrome_recursion(h, tmp->next);
	if (tmp->n != (*h)->n)
		return (0);
	(*h) = (*h)->next;
	return (res);
}
/**
 * is_palindrome - function that checks if a singly linked list is a palindrome
 * @head: pointer to head of list
 * Return: 0 if it is not a palindrome, 1 if it is a palindrome
 */
int is_palindrome(listint_t **head)
{
	listint_t **h = head;

	return (is_palindrome_recursion(h, *head));
}
