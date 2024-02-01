#include "binary_trees.h"
#include <limits.h>

int bst_checker(const binary_tree_t *tree, int low, int high);

/**
 *binary_tree_is_bst - Function that check if a tree is a
 *                     valid binary search tree
 *
 *@tree: Pointer to the root of the node to check
 *
 *Return: 1 if valid BST or 0
 */

int binary_tree_is_bst(const binary_tree_t *tree)
{
	if (tree == NULL)
		return (0);
	return (bst_checker(tree, INT_MIN, INT_MAX));
}


/**
 *bst_checker - Checks if a binary tree is a valid binary search tree
 *
 *@tree: Pointer to the root node of the tree to check
 *
 *@low: The value of the smallest node visited thus far
 *@high: The value of the largest node visited this far
 *
 *Return: If the tree is a valid BST, 1, otherwise, 0
 */

int bst_checker(const binary_tree_t *tree, int low, int high)
{
	if (tree != NULL)
	{
		if (tree->n < low || tree->n > high)
			return (0);
		return (bst_checker(tree->left, low, tree->n - 1) &&
			bst_checker(tree->right, tree->n + 1, high));
	}
	return (1);
}
