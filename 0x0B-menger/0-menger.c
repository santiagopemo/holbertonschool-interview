#include "menger.h"

/**
 * menger - function that draws a 2D Menger Sponge
 * @level: the level of the Menger Sponge to draw
 */
void menger(int level)
{
	int i, j, p, ti, tj;

	p = pow(3, level);
	for (i = 0; i < p; i++)
	{
		for (j = 0; j < p; j++)
		{
			for (ti = i, tj = j; ti > 0 || tj > 0; ti /= 3, tj /= 3)
			{
				if (ti % 3 == 1 && tj % 3 == 1)
				{
					putchar(' ');
					break;
				}
			}
			if (ti == 0 || tj == 0)
				putchar('#');
		}
		putchar('\n');
	}
}
