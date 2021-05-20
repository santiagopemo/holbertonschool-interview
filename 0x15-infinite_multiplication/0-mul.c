#include "holberton.h"
#include <stdio.h>

char *digit_mul_rev(char * num1, int len_num1, char digit, int zeros)
{
	int i, len_malloc, mul, k;
	char *rev_result;

	len_malloc = len_num1 * sizeof(char) + 2 + zeros;
	rev_result = malloc(len_malloc);
	if (rev_result == NULL)
	{
		print_string("Error\n");
		exit (98);
	}
	for (i = 0; i < zeros; i++)
		rev_result[i] = '0';
	len_num1--;
	for (k = 0; len_num1 >= 0 ; i++, len_num1--)
	{
		mul = (num1[len_num1] - '0') * (digit - '0') + k;
		
		rev_result[i] = (char)((mul % 10) + '0');
		k = mul / 10;
	}
	if (k > 0)
	{
		rev_result[i] = (char)(k + '0');
		i++;
	}
	rev_result[i] = '\0';
	return (rev_result);
}

char *str_rev_sum(char *num1, int len1, char* num2, int len2)
{
	int i, j, k, l, a, b, sum, len_malloc;
	char *res;

	len_malloc = (len1 > len2 ? len1 : len2) + 2;
	res = malloc(sizeof(char) * len_malloc);
	if (res == NULL)
	{
		print_string("Error\n");
		exit (98);
	}
	for (i = j = k = l = 0; num2[j] != '\0'; l++)
	{
		a = num1[i] != '\0' ? (num1[i] - '0') : 0;
		b = num2[j] != '\0' ? (num2[j] - '0') : 0;
		sum = a + b + k;
		res[l] = (char)((sum % 10) + '0');
		k = sum / 10;
		if (i < len1)
			i++;
		if (j < len2)
			j++;
	}
	if (k > 0)
	{
		res[l] = (char)(k + '0');
		l++;
	}
	res[l] = '\0';
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

	for (i = 0; num[i] != '\0'; i++)
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
	int i, j, len1, len2;
	char *mul, *res, *tmp;

	if (argc < 3)
	{
		print_string("Error\n");
		exit (98);
	}
	len1 = num_len(argv[1]);
	len2 = num_len(argv[2]);
	if (len1 == -1 || len2 == -1)
		exit(98);
	res = malloc(sizeof(char) * 2);
	if (res == NULL)
	{
		print_string("Error\n");
		exit (98);
	}
	res[0] = '0';
	res[1] = '\0';
	for (i = 0, j = len2 - 1; i < len2; i++, j--)
	{
		mul = digit_mul_rev(argv[1], len1, argv[2][j], i);
		tmp = res;
		res = str_rev_sum(res, num_len(res), mul, num_len(mul));
		free(tmp);
		free(mul);
	}
	for (i = num_len(res) - 1; i >= 0; i--)
	{
		_putchar(res[i]);
	}
	print_string("\n");
	free(res);
	return (0);
}