#include "holberton.h"

/**
 * wildcmp - compares two strings
 * @s1: First string
 * @s2: Second string
 * Return: 1 if the strings can be considered identical, 0 if not
 */

int wildcmp(char *s1, char *s2)
{
	if (!*s1)
	{
		if (*s2 == '*')
			return (wildcmp(s1, s2 + 1));
		return (!*s2);
	}
	if (*s2 == '*')
		return (wildcmp(s1 + 1, s2) || wildcmp(s1, s2 + 1));
	if (*s1 == *s2)
		return (wildcmp(s1 + 1, s2 + 1));
	return (0);
}
