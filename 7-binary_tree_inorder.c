#include "binary_trees.h"

/**
 *binary_tree_inorder - Function that traverse using in-order
 *                      traversal
 *
 *@tree: Pointer to the root node of tree to traverse
 *@func: Pointer to the function call of each node
 *
 *Return: Void
 */

void binary_tree_inorder(const binary_tree_t *tree, void (*func)(int))
{

	if (func == NULL)
		return;
	if (tree == NULL)
		return;

	binary_tree_inorder(tree->left, func);
	func(tree->n);
	binary_tree_inorder(tree->right, func);
}
