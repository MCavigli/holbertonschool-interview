#ifndef BINARY_TREES_H
#define BINARY_TREES_H
#include <stdlib.h>
#include <limits.h>
#include <stddef.h>
#include <string.h>
/**
 * struct binary_tree_s - Binary tree node
 *
 * @n: Integer stored in the node
 * @parent: Pointer to the parent node
 * @left: Pointer to the left child node
 * @right: Pointer to the right child node
 */
struct binary_tree_s
{
	int n;
	struct binary_tree_s *parent;
	struct binary_tree_s *left;
	struct binary_tree_s *right;
};

typedef struct binary_tree_s binary_tree_t;
typedef struct binary_tree_s avl_t;

void binary_tree_print(const binary_tree_t *tree);

int binary_tree_is_avl(const binary_tree_t *tree);
int get_tree_height(const binary_tree_t *t);
int calc_height_diff(int left, int right);
#endif /* BINARY_TREES_H */
