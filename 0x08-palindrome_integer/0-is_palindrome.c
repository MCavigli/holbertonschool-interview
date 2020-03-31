#include "palindrome.h"
#include <stdio.h>

/**
 * is_palindrome - Checks if a number is a palindrome
 * @n: the number to check
 * Return: 1 if @n is a palindrome, 0 if not
 */

int is_palindrome(unsigned long n)
{
	unsigned long temp = rec(n, 0);

	if (temp == n)
		return (1);
	else
		return (0);
}

/**
 * rec - Recursively traverses the number
 * @n: the number to check
 * @temp: specific numbers in @n
 * Return: @temp
 */

unsigned long rec(unsigned long n, unsigned long temp)
{
	if (n == 0)
		return (temp);
	temp = (temp * 10) + (n % 10);
	return (rec(n / 10, temp));
}
