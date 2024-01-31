#include "binary_trees.h"

/**
 *binary_tree_is_full - Function that checks if binary tree
 *                      is full
 *
 *@tree: Pointer to the root node of the tree
 *
 *Return: 0 if the tree is NULL or the status of
 *        the binary tree
 */


int binary_tree_is_full(const binary_tree_t *tree)
{
	int right_tree = 0;
	int left_tree = 0;

	if (tree == NULL)
		return (0);


	if (tree->left == NULL && tree->right == NULL)
		return (1);
	if (tree->left == NULL && tree->right != NULL)
		return (0);
	if (tree->left != NULL && tree->right == NULL)
		return (0);

	left_tree = binary_tree_is_full(tree->left);
	right_tree = binary_tree_is_full(tree->right);

	if (right_tree == 1 && left_tree == 1)
		return (1);

	return (0);
}
