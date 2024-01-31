#include "binary_trees.h"

/**
 *binary_tree_nodes - Function that counts the nodes with at least 1
 *                    child
 *
 *@tree: Pointer to the root node of the tree to count the nodes
 *
 *Return: 0 if tree is NULL, NULL pointer if not node or
 *        number of nodes
 */

size_t binary_tree_nodes(const binary_tree_t *tree)
{
	if (tree != NULL && (tree->left != NULL || tree->right != NULL))
		return (binary_tree_nodes(tree->left) +
			binary_tree_nodes(tree->right) + 1);
	return (0);
}
