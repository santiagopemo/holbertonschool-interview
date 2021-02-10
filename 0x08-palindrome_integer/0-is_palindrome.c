#include "palindrome.h"

/**
 * is_palindrome - function that checks whether or
 * not a given unsigned integer is a palindrome
 * @n: number to be checked
 * Return: 1 if n is a palindrome, and 0 otherwise
 */
int is_palindrome(unsigned long n)
{
	unsigned long tens, tmp;

	for (tens = 1, tmp = n; tmp > 10; tmp /= 10, tens *= 10)
		continue;
	if (tens == 1)
		return (1);
	for (tmp = n; tens >= 10; tens /= 100)
	{
		if ((tmp / tens) != (tmp % 10))
			return (0);
		tmp -= ((tmp / tens) * tens);
		tmp /= 10;
	}
	return (1);
}
