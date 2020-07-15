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
		if (node->right && node->n < node->right->n
		    && node->right->n > node->left->n)
		{
			tmp = node->right->n;
			node->right->n = node->n;
			node->n = tmp;
			bigNode = node->right;
		}
		else if (node->n < node->left->n)
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
	heap_t *l = node;
	heap_t *r = node;

	while (l->left)
	{
		l = l->left;
	}
	while (r->right)
	{
		r = r->right;
	}
	if (l->n < r->n)
		return (l);
	else
		return (r);

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

	if (!*root || !root)
		return (0);

	if (!(*root)->left && !(*root)->right)
	{
		free(*root);
		return ((*root)->n);
	}
	currentData = (*root)->n;
	lastNode = findMin(*root);
	if (lastNode->parent)
	{
		if (lastNode->parent->left == lastNode)
			lastNode->parent->left = NULL;
		else
			lastNode->parent->right = NULL;
	}
	(*root)->n = lastNode->n;
	free(lastNode);
	heapIt(*root);

	return (currentData);
}
