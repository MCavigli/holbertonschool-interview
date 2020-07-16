#include "holberton.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/** main - Entry point. Multiplies two numbers
 * @argc: number of args
 * @argv: argument vector
 * Return: The product or 98 on failure
 */

int main(int argc, char *argv[])
{
	int argLen1, argLen2;
	int c, n1, n2, sum, i, j;
	int i_n1, i_n2;
	int *product;

	if (argc != 3)
	{
		printf("Error\n");
		exit(98);
	}
	argLen1 = strlen(argv[1]);
	argLen2 = strlen(argv[2]);

	product = calloc(argLen1 + argLen2, sizeof(*product));

	i_n1 = 0;
	i_n2 = 0;
	for (i = argLen1 - 1; i >= 0; i--)
	{
		c = 0;
		n1 = argv[1][i] - '0';
		i_n2 = 0;

		for (j = argLen2 - 1; j >= 0; j--)
		{
			n2 = argv[2][j] - '0';
			sum = ((n1 * n2) + (product[i + j])) + c;
			product[i + j] = sum % 10;
			c = sum / 10;
			i_n2++;
		}
		if (c > 0)
			product[i_n1 + i_n2] += c;
		i_n1++;
	}
	if (product[0] == 0)
		i = 1;
	else
		i = 0;

	while (i < argLen1 + argLen2)
	{
		printf("%d", product[i]);
		i++;
	}
	printf("\n");
	free(product);
	return (EXIT_SUCCESS);
}
