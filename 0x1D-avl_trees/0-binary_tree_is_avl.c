#include "binary_trees.h"

/**
 * calc_height_diff - gets the difference in tree height
 * @left: left side of tree
 * @right: right side of tree
 * Return: difference in height
 */
int calc_height_diff(int left, int right)
{
	if (right > left)
		return (right - left);
	else
		return (left - right);
}

/**
 * get_tree_height - returns heigh of binary tree
 * @t: the tree
 * Return: height of the tree, 0 if NULL
 */

int get_tree_height(const binary_tree_t *t)
{
	int l_height;
	int r_height;

	if (!t)
		return (0);

	if (t->left)
		l_height = 1 + get_tree_height(t->left);
	else
		l_height = 0;
	if (t->right)
		r_height = 1 + get_tree_height(t->right);
	else
		r_height = 0;

	if (l_height > r_height)
		return (l_height);
	else
		return (r_height);
}

/**
 * binary_tree_is_avl - checks if a binary tree is a valid AVL Tree
 * @tree: Pointer to the root node of the tree to check
 * Return: 1 if @tree is valid, 0 otherwise or if tree is NULL
 */

int binary_tree_is_avl(const binary_tree_t *tree)
{
	int height = 0;
	int l_height;
	int r_height;

	if (!tree)
		return (0);

	if (tree->left)
		l_height = get_tree_height(tree->left);
	else
		l_height = 0;
	if (tree->right)
		r_height = get_tree_height(tree->right);
	else
		r_height = 0;
	height = calc_height_diff(l_height, r_height);
	if (height > 1)
		return (0);
	if (!(tree->left) && !(tree->right))
		return (1);
	else
		return (binary_tree_is_avl(tree->left) && binary_tree_is_avl(tree->right));
}
