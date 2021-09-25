#include "slide_line.h"

/**
* slide_line - slides a line left or right
* @line: line to slide
* @size: size of line array
* @direction: left or right
*
* Return: 0 on failure, else 1
*/
int slide_line(int *line, size_t size, int direction)
{
	if (line == NULL || size == 0)
		return (0);

	if (direction == SLIDE_LEFT)
		return (slide_line_left(line, size));
	if (direction == SLIDE_RIGHT)
		return (slide_line_right(line, size));

	return (0);

}

/**
* slide_line_left - slides a line to the left
* @line: line to slide
* @size: size of line array
*
* Return: always 1
*/
int slide_line_left(int *line, size_t size)
{
	int i, j, merged = 0, target = size;

	for (i = 1; i < target; i++)
	{
		if (line[i] == 0)
			continue;

		for (j = i - 1; j >= 0; j--)
		{
			if (line[j] != 0)
			{
				if (merged || line[j] != line[i])
				{
					line[j + 1] = line[i];
					merged = 0;
				}
				else
				{
					line[j] += line[i];
					merged = 1;
				}
				if (j + 1 != i || merged)
					line[i] = 0;
				break;
			}
			if (j == 0)
			{
				line[0] = line[i];
				line[i] = 0;
			}
		}
	}

	return (1);
}

/**
* slide_line_right - slides a line to the right
* @line: line to slide
* @size: size of line array
*
* Return: always 1
*/
int slide_line_right(int *line, size_t size)
{
	int i, j, merged = 0, target = size;

	for (i = target - 2; i >= 0; i--)
	{
		if (line[i] == 0)
			continue;

		for (j = i + 1; j < target; j++)
		{
			if (line[j] != 0)
			{
				if (merged || line[j] != line[i])
				{
					line[j - 1] = line[i];
					merged = 0;
				}
				else
				{
					line[j] += line[i];
					merged = 1;
				}
				if (j - 1 != i || merged)
					line[i] = 0;
				break;
			}
			if (j == target - 1)
			{
				line[target - 1] = line[i];
				line[i] = 0;
			}
		}
	}

	return (1);
}
