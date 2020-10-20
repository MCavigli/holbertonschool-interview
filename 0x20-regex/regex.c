#include "regex.h"
/**
 * regex_match - checks whether a given pattern matches a given string
 * @str: string to scan
 * @pattern: the regular expression
 * Return: 1 if pattern matches string, 0 if not
 */

int regex_match(char const *str, char const *pattern)
{
	if (!pattern || !str)
		return (0);
	if (!*pattern)
		return (!*str);

	return (0);
}
