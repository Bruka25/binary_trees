#include "binary_trees.h"

/**
 *binary_tree_height - Function that measures the height of
 *                     a binary tree
 *
 *@tree: Pointer to the root node of the tree to measure
 *
 *Return: Height of a tree or 0 if the tree is NULL
 */

size_t binary_tree_height(const binary_tree_t *tree)
{
	size_t left_height = 0;
	size_t right_height = 0;

	if (tree == NULL)
		return (0);

	if (tree->left != NULL)
		left_height = binary_tree_height(tree->left) + 1;

	if (tree->right != NULL)
		right_height = binary_tree_height(tree->right) + 1;

	return (left_height > right_height ? left_height : right_height);
}
