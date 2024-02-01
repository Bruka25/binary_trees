#include "binary_trees.h"
#include <limits.h>


size_t avl_tree_height(const binary_tree_t *tree);
int avl_helper(const binary_tree_t *tree, int low, int high);

/**
 *binary_tree_is_avl - Function that checks if a binary tree is
 *                     a valid AVL tree
 *
 *@tree: Pointer to the root node of the tree to check
 *
 *Return: 0 if tree is NULL or if not valid AVL
 *        otherwise 1 if the tree if valid AVL
 */

int binary_tree_is_avl(const binary_tree_t *tree)
{
	if (tree == NULL)
		return (0);
	return (avl_helper(tree, INT_MIN, INT_MAX));
}


/**
 *avl_tree_height - Function that measures the height of
 *                     a binary tree
 *
 *@tree: Pointer to the root node of the tree to measure
 *
 *Return: Height of a tree or 0 if the tree is NULL
 */

size_t avl_tree_height(const binary_tree_t *tree)
{
	size_t left_height = 0;
	size_t right_height = 0;

	if (tree == NULL)
		return (0);

	if (tree->left != NULL)
		left_height = avl_tree_height(tree->left) + 1;

	if (tree->right != NULL)
		right_height = avl_tree_height(tree->right) + 1;

	return (left_height > right_height ? left_height : right_height);
}

/**
 *avl_helper - Checks if a binary tree is a valid AVL tree
 *
 *@tree: A pointer to the root node of the tree to check
 *@low: The value of the smallest node visited thus far
 *@high: The value of the largest node visited this far
 *
 *Return: If the tree is a valid AVL tree, 1
 *        otherwise 0
 */
int avl_helper(const binary_tree_t *tree, int low, int high)
{
	size_t left_hgt, right_hgt, diff;

	if (tree != NULL)
	{
		if (tree->n < low || tree->n > high)
			return (0);
		left_hgt = avl_tree_height(tree->left);
		right_hgt = avl_tree_height(tree->right);
		diff = left_hgt > right_hgt ? left_hgt - right_hgt : right_hgt - left_hgt;
		if (diff > 1)
			return (0);
		return (avl_helper(tree->left, low, tree->n - 1) &&
			avl_helper(tree->right, tree->n + 1, high));
	}
	return (1);
}
