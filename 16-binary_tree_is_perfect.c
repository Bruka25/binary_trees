#include "binary_trees.h"

int tree_power(int exp);
size_t bin_tree_height(const binary_tree_t *tree);
size_t bin_tree_size(const binary_tree_t *tree);

/**
 *binary_tree_is_perfect - Function that checks if a binary tree is 
 *                         perfect
 *
 *@tree: Pointer to the root of the node
 *
 *Return: 0 if the tree is NULL or the status of the tree
 */

int binary_tree_is_perfect(const binary_tree_t *tree)
{
	int left_tree;
        int right_tree;
	int size;
	int power;

	if (tree == NULL)
		return (0);

	left_tree = bin_tree_height(tree->left);
	right_tree = bin_tree_height(tree->right);
	size = bin_tree_size(tree);

	if (size == 1)
		return (1);
	if (left_tree >= 0 && right_tree >= 0 && left_tree == right_tree)
	{
		power = tree_power(left_tree + 1);

		if (power - 1 == size)
			return (1);
	}

	return (0);
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

/**
 *bin_tree_size - Function that measures the size of
 *                   a binary tree
 *
 *@tree: Pointer to the root node of the tree to measure
 *
 *Return: 0 if tree is NULL or size of the tree
 */

size_t bin_tree_size(const binary_tree_t *tree)
{
	size_t tree_size;
	size_t left_tree = 0;
	size_t right_tree = 0;

	if (tree == NULL)
		return (0);

	if (tree->left != NULL)
		left_tree = bin_tree_size(tree->left);

	if (tree->right != NULL)
		right_tree = bin_tree_size(tree->right);

	tree_size = left_tree + right_tree + 1;
	return (tree_size);

}

/**
 * tree_power - get the power of 2 for a given number
 *
 *@exp: exponent
 *
 *Return: power of 2 for given exponent
 */

int tree_power(int exp)
{
	int pow, i;

	for (i = 0, pow = 1; i <= exp; i++)
		pow *= 2;

	return (pow);
}
