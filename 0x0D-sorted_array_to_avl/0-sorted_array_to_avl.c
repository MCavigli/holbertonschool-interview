#include "binary_trees.h"

/**
 * noder - fills out the tree and givces values to the nodes
 * @array: the array
 * @size: the changing size of the array
 * @parent: the parent node
 * Return: Pointer to the new tree
 */
binary_tree_t *noder(int *array, size_t size, binary_tree_t *parent)
{
	avl_t *newnode = NULL;
	size_t mid;

	if (size)
	{
		mid = (size / 2);
		if (size % 2 == 0)
			mid--;

		newnode = malloc(sizeof(avl_t));
		if (!newnode)
			return (NULL);

		newnode->n = array[mid];
		newnode->parent = parent;

		if (size > 1)
		{
			newnode->left = noder(array, mid, newnode);
			newnode->right = noder(array, size - mid - 1, newnode);
		}
		else
		{
			newnode->left = NULL;
			newnode->right = NULL;
		}
	}
	return (NULL);
}
/**
 * recursive_tree - Function that calls itself and builds tree
 * @array: pointer to the array
 * @start: beginning of the array
 * @end: end of the array
 * Return: Root of the tree
 */
binary_tree_t *recursive_tree(int *array, size_t start, size_t end)
{
	if (start > end)
		return (NULL);

	size_t mid = (start + end) / 2;
	if (mid % 2 == 0)
		mid--;
	avl_t *root = NULL;
	root = malloc(sizeof(avl_t));
	if (!root)
		return (NULL);

	root->n = array[mid];
	root->parent = NULL;

	root->left = noder(array, mid - 1, root);
	root->right = noder(array, mid + 1, root);

	return (root);
}

/**
 * sorted_array_to_avl - Builds an AVL tree from an array
 * @array: pointer to the first element of the array to be converted
 * @size: number of elements in the array
 * Return: pointer to the root node of the created AVL tree, or NULL on failure
 */
avl_t *sorted_array_to_avl(int *array, size_t size)
{
	if (!array)
		return (NULL);

	binary_tree_t *root = recursive_tree(array, 0, size - 1);

	return (root);
}
