#include "binary_trees.h"


void level_order(const binary_tree_t *tree, void (*func)(int), int height);
size_t bin_tree_height(const binary_tree_t *tree);

/**
 *binary_tree_levelorder - Function that goes through a binary using
 *                         level order treaversal
 *
 *@tree: Pointer to the root node to traverse
 *@func: Pointer to the function to call
 *
 *Return: Void
 */


void binary_tree_levelorder(const binary_tree_t *tree, void (*func)(int))
{
	int height, total;

	if (tree == NULL || func == NULL)
		return;

	height = bin_tree_height(tree);
	for (total = 0; total <= height; total++)
		level_order(tree, func, total);
}

/**
 *level_order - binary tree level ordering using recursion
 *
 *@tree: node of a tree, initially the root
 *@func: function pointer to use at each level
 *@height: height of tree from current node
 *
 *Return: Void
 */

void level_order(const binary_tree_t *tree, void (*func)(int), int height)
{
	if (tree == NULL)
		return;
	else if (height == 0)
		func(tree->n);
	else
	{
		level_order(tree->left, func, height - 1);
		level_order(tree->right, func, height - 1);
	}
}

/**
 *bin_tree_height - Function that measures the height of
 *                     a binary tree
 *
 *@tree: Pointer to the root node of the tree to measure
 *
 *Return: Height of a tree or 0 if the tree is NULL
 */

size_t bin_tree_height(const binary_tree_t *tree)
{
	size_t left_height = 0;
	size_t right_height = 0;

	if (tree == NULL)
		return (0);

	if (tree->left != NULL)
		left_height = bin_tree_height(tree->left) + 1;

	if (tree->right != NULL)
		right_height = bin_tree_height(tree->right) + 1;

	return (left_height > right_height ? left_height : right_height);
}
