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
 * @treeSize: size of the tree
 * Return: Value of smallest node
 */
binary_tree_t *findMin(heap_t *node, int treeSize)
{
	int count = 0;
	int bitMove;

	while (1 << (count + 1) <= treeSize)
	{
		count++;
	}
	count--;
	while (count >= 0)
	{
		count--;
		bitMove = 1 << count;
		if (treeSize & bitMove)
		{
			if (node->right)
				node = node->right;
			else
				break;
		}
		else
		{
			if (node->left)
				node = node->left;
			else
				break;
		}
	}
	return (node);
}

/**
 * getTreeSize - recursively counts nodes in tree
 * @root: top of the tree
 * Return: number of nodes in tree
 */

int getTreeSize(heap_t *root)
{
	int l_height = 0;
	int r_height = 0;

	if (!root)
		return (0);
	l_height = getTreeSize(root->left);
	r_height = getTreeSize(root->right);

	if (l_height > r_height)
		return (l_height + 1);
	else
		return (r_height + 1);
}

/**
 * heap_extract - extracts the root node of a max binary heap
 * @root: double pointer to root node of heap
 * Return: value stored in root node, 0 if failed
 */

int heap_extract(heap_t **root)
{
	heap_t *lastNode;
	int treeSize;
	int currentData;

	if (!*root || !root)
		return (0);

	if (!(*root)->left && !(*root)->right)
	{
		free(*root);
		return ((*root)->n);
	}
	currentData = (*root)->n;
	treeSize = getTreeSize(*root);
	lastNode = findMin(*root, treeSize);
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
