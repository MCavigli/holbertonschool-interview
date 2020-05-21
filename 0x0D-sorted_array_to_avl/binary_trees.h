#ifndef _BINARY_TREES_H_
#define _BINARY_TREES_H_
#include <stdlib.h>

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

/* Given prototype */
avl_t *sorted_array_to_avl(int *array, size_t size);

/* Prototypes to print tree */
void binary_tree_print(const binary_tree_t *tree);

/* Helper funcion section */
avl_t *recursive_tree(int *array, size_t start, size_t end, size_t size);
avl_t *noder(int *array, size_t size, avl_t *parent);
#endif /* _BINARY_TREES_H_ */
