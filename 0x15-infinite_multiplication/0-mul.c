#include "holberton.h"

int *multiplication(char *num1, int len1, char *num2, int len2)
{
	int i, j, mul, *res;

	res = malloc((len2 + len1) * sizeof(int));
	if (res == NULL)
	{
		print_string("Error\n");
		exit(98);
	}
	for (i = 0; i < len1 + len2; i++)
		res[i] = 0;
	for (i = len2 - 1; i >= 0; i--)
	{
		for (j = len1 - 1; j >= 0; j--)
		{
			mul = (num2[i] - '0') * (num1[j] - '0');
			res[i + j + 1] += mul % 10;
			res[i + j] += mul / 10;
			if (res[i + j + 1] >= 10)
			{
				res[i + j] += res[i + j + 1] / 10;
				res[i + j + 1] %= 10;
			}
		}
	}
	return (res);
}

void print_string(char *str)
{
	int i;

	for (i = 0; str[i] != '\0'; i++)
	{
		_putchar(str[i]);
	}
}

int num_len(char *num)
{
	int i = 0;

	for (; num[i] != '\0'; i++)
	{
		if (num[i] < 48 || num[i] > 57)
			return (-1);
	}
	return (i);
}
/**
 * main - program that multiplies two positive numbers.
 *
 * Return: 0 un success, 98 if not.
 */
int main(int argc, char **argv)
{
	int i, len1, len2, *res;

	if (argc != 3)
	{
		print_string("Error\n");
		exit(98);
	}
	len1 = num_len(argv[1]);
	len2 = num_len(argv[2]);
	if (len1 == -1 || len2 == -1)
	{
		print_string("Error\n");
		exit(98);
	}
	if (argv[1][0] == '0' || argv[2][0] == '0')
	{
		print_string("0\n");
		return (0);
	}
	res = multiplication(argv[1], len1, argv[2], len2);
	if (!res[0])
		i = 1;
	else
		i = 0;
	for (; i < len1 + len2; i++)
		_putchar(res[i] + '0');
	_putchar('\n');
	free(res);
	return (0);
}
