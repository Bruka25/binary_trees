#include "binary_trees.h"

/**
 *binary_tree_size - Function that measures the size of
 *                   a binary tree
 *
 *@tree: Pointer to the root node of the tree to measure
 *
 *Return: 0 if tree is NULL or size of the tree
 */

size_t binary_tree_size(const binary_tree_t *tree)
{
	size_t tree_size;
	size_t left_tree = 0;
	size_t right_tree = 0;

	if (tree == NULL)
		return (0);

	if (tree->left != NULL)
		left_tree = binary_tree_size(tree->left);

	if (tree->right != NULL)
		right_tree = binary_tree_size(tree->right);

	tree_size = left_tree + right_tree + 1;
	return (tree_size);

}
