#include "binary_trees.h"

/**
 * heap_insert - inserts a value into a Max Binary Heap
 * @root: double pointer to the root node of the Heap
 * @value: value stored in the node to be inserted
 * Return: pointer to the inserted node, or NULL on failure
 */

heap_t *heap_insert(heap_t **root, int value)
{

	heap_t *tmp = *root;
	heap_t *newNode = malloc(sizeof(heap_t));

	if (!newNode)
		return (NULL);
	newNode->n = value;

	if (!tmp)
	{
		*root = newNode;
		return (newNode);
	}
	else if (value > newNode->n)
		newNode->right = heap_insert(&newNode->right, value);
	else
		newNode->left = heap_insert(&newNode->left, value);
	return (newNode);
}

/**
 * placement - places new node at the end of the tree
 * @cn: double pointer to the root of a tree
 * @value: the value of the new node
 * Return: pointer to the place to new node
 */
