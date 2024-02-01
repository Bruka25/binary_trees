#include "binary_trees.h"


size_t bal_tree_height(const binary_tree_t *tree);

/**
 *binary_tree_balance - Function that measures the balance factor of
 *                      a binary tree
 *
 *@tree: Pointer to the root node
 *
 *Return: 0 if the tree is NULL or balance factor measure
 */

int binary_tree_balance(const binary_tree_t *tree)
{
	int left_tree, right_tree;

	if (tree == NULL)
		return (0);

	left_tree = bal_tree_height(tree->left);
	right_tree = bal_tree_height(tree->right);

	return (left_tree - right_tree);
}


/**
 *bal_tree_height - Function that measures the height of
 *                     a binary tree
 *
 *@tree: Pointer to the root node of the tree to measure
 *
 *Return: Height of a tree or 0 if the tree is NULL
 */

size_t bal_tree_height(const binary_tree_t *tree)
{
	int left, right;

	if (tree == NULL)
		return (-1);

	if (tree->left == NULL && tree->right == NULL)
		return (0);

	left = bal_tree_height(tree->left) + 1;
	right = bal_tree_height(tree->right) + 1;

	if (left > right)
		return (left);
	else
		return (right);
}
