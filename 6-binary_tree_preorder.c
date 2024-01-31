#include "binary_trees.h"

/**
 *binary_tree_preorder - Function that goes through tree using
 *                       pre-order traversal
 *
 *@tree: Pointer to the root node to traverse
 *@func: Pointer to the function to call for each node
 *
 *Return: Void
 */
void binary_tree_preorder(const binary_tree_t *tree, void (*func)(int))
{

	if (func == NULL)
		return;
	if (tree == NULL)
		return;

	func(tree->n);
	binary_tree_preorder(tree->left, func);
	binary_tree_preorder(tree->right, func);
}
