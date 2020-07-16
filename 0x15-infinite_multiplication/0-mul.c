#include "holberton.h"
#include <stdio.h>

/** main - Entry point. Multiplies two numbers
 * @argc: number of args
 * @argv: argument vector
 * Return: The product or 98 on failure
 */

int main(int argc, char *argv[])
{
	char *one, *two;
	int product;

	if (argc != 3)
		return (98);

	one = argv[1];
	two = argv[2];
	product = (int)one * (int)two;

	printf("One: %s\n", one);
	printf("Two: %s\n", two);
	printf("Product: %i\n", product);
	return (1);
}
