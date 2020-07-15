#include "binary_trees.h"

/**
 * heapIt - heapifies the node through the tree
 * @tree: the tree
 */
void heapIt(heap_t *tree)
{
	binary_tree_t *node;
	binary_tree_t *bigNode;
	int tmp;

	if (!tree)
		return;
	node = tree;
	while (node->left)
	{
		bigNode = node->left;
		if (node->right)
		{
			if (node->n < node->right->n && node->right->n > node->left->n)
			{
				tmp = node->right->n;
				node->right->n = node->n;
				node->n = tmp;
				bigNode = node->right;
			}
		}
		if (node->n < node->left->n)
		{
			tmp = node->left->n;
			node->left->n = node->n;
			node->n = tmp;
		}
		node = bigNode;
	}
}

/**
 * findMin - finds the smallest node
 * @node: root of tree
 * Return: Value of smallest node
 */
binary_tree_t *findMin(heap_t *node)
{
	heap_t *current = node;
	heap_t *l = findMin(node->left);
	heap_t *r = findMin(node->right);
	int res = node->n;

	if (!node)
		return (0);

	if (l->n < res)
		current = l;
	if (r->n < res)
		current = r;
	return (current);
}

/**
 * getTreeSize - recursively counts nodes in tree
 * @root: top of the tree
 * Return: number of nodes in tree
 */

int getTreeSize(heap_t *root)
{
	int res = 0;

	if (!root)
		return (0);
	if (root->left && root->right)
		res++;
	res += (getTreeSize(root->left) + getTreeSize(root->right));
	return (res);
}

/**
 * heap_extract - extracts the root node of a max binary heap
 * @root: double pointer to root node of heap
 * Return: value stored in root node, 0 if failed
 */

int heap_extract(heap_t **root)
{
	heap_t *lastNode;
	int currentData;

	if (!*root)
		return (0);

	currentData = (*root)->n;
	if (!(*root)->left && !(*root)->right)
	{
		free(*root);
		return (currentData);
	}
	lastNode = findMin(*root);
	(*root)->n = lastNode->n;
	free(lastNode);
	heapIt(*root);
	return (currentData);
}
