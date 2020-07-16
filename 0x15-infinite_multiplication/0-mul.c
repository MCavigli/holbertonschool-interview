#include "holberton.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
 * main - Entry point. Multiplies two numbers
 * @argc: number of args
 * @argv: argument vector
 * Return: The product or 98 on failure
 */

int main(int argc, char *argv[])
{
	int argLen1, argLen2, c, n1, n2, i, j, i_n1, i_n2;
	int *product;

	if (argc != 3)
	{
		printf("Error\n");
		exit(98);
	}
	argLen1 = strlen(argv[1]), argLen2 = strlen(argv[2]);
	product = malloc((argLen1 + argLen2) * sizeof(*product));
	if (!product)
		exit(98);
	i_n1 = 0, i_n2 = 0;
	for (i = argLen1 - 1; i >= 0; i--)
	{
		c = 0;
		n1 = argv[1][i] - '0';
		i_n2 = 0;
		for (j = argLen2 - 1; j >= 0; j--)
		{
			n2 = argv[2][j] - '0';
			c += (n1 * n2) + product[i_n1 + i_n2];
			product[i_n1 + i_n2] = c % 10;
			c = c / 10;
			i_n2++;
		}
		if (c > 0)
			product[i_n1 + i_n2] += c;
		i_n1++;
	}
	i = strlen((char *)product);
	while (i >= 0)
	{
		printf("%d", product[i]);
		i--;
	}
	printf("\n");
	free(product);
	return (1);
}
