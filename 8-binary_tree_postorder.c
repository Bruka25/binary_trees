#include "binary_trees.h"

/**
 *binary_tree_postorder - Function that goes through binary tree
 *                        in post order traversal
 *
 *@tree: Pointer to the root node of the tree to traverse
 *@func: Pointer to the function to call for each node
 *
 *Return: Void
 */

void binary_tree_postorder(const binary_tree_t *tree, void (*func)(int))
{

	if (func == NULL)
		return;
	if (tree == NULL)
		return;

	binary_tree_postorder(tree->left, func);
	binary_tree_postorder(tree->right, func);
	func(tree->n);
}
