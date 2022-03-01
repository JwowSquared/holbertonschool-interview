#include "holberton.h"

/**
* wildcmp - compares two strings with wildcard support
* @s1: string 1
* @s2: string 2
*
* Return: 1 if strings can be considered identical, else 0
*/
int wildcmp(char *s1, char *s2)
{
	/* Assumes s1 and s2 will never be NULL */
	/* Assumes s1 will never contain a wildcard */

	if (*s1 == '\0' && *s2 == '\0')
		return (1);

	if (*s2 == '*')
	{
		/* Handles consecutive wildcards */
		if (*(s2 + 1) == '*')
			return (wildcmp(s1, s2 + 1));

		if (wildcmp(s1, s2 + 1))
		{
			if (*s1 == '\0')
				return (1);
			return (s1 + 1, s2 + 2);
		}

		if (*s1 == '\0')
			return (0);
		return (wildcmp(s1 + 1, s2));
	}

	if (*s1 == *s2)
		return (wildcmp(s1 + 1, s2 + 1));

	return (0);
}
