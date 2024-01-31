#include "binary_trees.h"

/**
 *binary_tree_is_root - Function that checks if a given node
 *                      is a root
 *
 *@node: Pointer to the node to check
 *
 *Return: 1 if a node is root, or 0 if a node is NULL or
 *        or if not a root node
 */

int binary_tree_is_root(const binary_tree_t *node)
{
	if (node == NULL)
		return (0);

	if (node->parent == NULL)
		return (1);

	return (0);
}

