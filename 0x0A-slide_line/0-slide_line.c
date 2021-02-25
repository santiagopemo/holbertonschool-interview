#include "slide_line.h"

/**
 * slide_left - slides and merges an array of integers to the left
 * @line: points to an array of integers
 * @size: line array elements
 */
void slide_left(int *line, size_t size)
{
	int i, j;

	for (i = 0; i < (int) size; i++)
	{
		for (j = i + 1; j < (int) size; j++)
		{
			if (line[i] == 0 && line[j] > 0)
			{
				line[i] += line[j];
				line[j] = 0;
				i -= 1;
				break;
			}
			if (line[j] > 0 && line[i] == line[j])
			{
				line[i] += line[j];
				line[j] = 0;
				break;
			}
		}
	}
}

/**
 * slide_right - slides and merges an array of integers to the right
 * @line: points to an array of integers
 * @size: line array elements
 */
void slide_right(int *line, size_t size)
{
	int i, j;

	for (i = size - 1; i >= 0; i--)
	{
		for (j = i - 1; j >= 0; j--)
		{
			if (line[i] == 0 && line[j] > 0)
			{
				line[i] += line[j];
				line[j] = 0;
				i += 1;
				break;
			}
			if (line[j] > 0 && line[i] == line[j])
			{
				line[i] += line[j];
				line[j] = 0;
				break;
			}
		}
	}
}

/**
 * slide_line - function that slides and merges an array of integers
 * @line: points to an array of integers
 * @size: line array elements
 * @direction: merge direction
 * Return: 1 upon success, or 0 upon failure
 */
int slide_line(int *line, size_t size, int direction)
{
	if (direction == SLIDE_LEFT)
	{
		slide_left(line, size);
		return (1);
	}
	if (direction == SLIDE_RIGHT)
	{
		slide_right(line, size);
		return (1);
	}
	return (0);
}
