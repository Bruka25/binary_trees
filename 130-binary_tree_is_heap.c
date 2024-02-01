#include "binary_trees.h"

int balance(const binary_tree_t *tree);
int perfect_tree(const binary_tree_t *tree);
int binary_tree_is_perfect(const binary_tree_t *tree);

/**
 *binary_tree_is_heap - Function that checks if a binary tree is a
 *                      valid max binary heap
 *
 *@tree: Pointer to the root node of the tree to check
 *
 *Return: 1 if a valid tree or 0 if not
 */


int binary_tree_is_heap(const binary_tree_t *tree)
{
	int bin_val;

	if (tree == NULL)
	{
		return (0);
	}
	if (tree->left && tree->left->n > tree->n)
	{
		return (0);
	}
	if (tree->right && tree->right->n > tree->n)
	{
		return (0);
	}
	if (binary_tree_is_perfect(tree))
	{
		return (1);
	}
	bin_val = balance(tree);
	if (bin_val == 0)
	{
		return (binary_tree_is_perfect(tree->left)
			&& binary_tree_is_heap(tree->right));
	}
	if (bin_val == 1)
	{
		return (binary_tree_is_heap(tree->left)
			&& binary_tree_is_perfect(tree->right));
	}
	else
	{
		return (0);
	}
}



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


/**
 *balance - Measures balance factor of a binary tree
 *
 *@tree: tree to balance
 *
 *Return: The balanced factor of the balanced tree
 */

int balance(const binary_tree_t *tree)
{
	int right_tree = 0, left_tree = 0, result = 0;

	if (tree)
	{
		left_tree = ((int)binary_tree_height(tree->left));
		right_tree = ((int)binary_tree_height(tree->right));
		result = left_tree - right_tree;
	}
	return (result);
}

/**
 * perfect_tree - function that says if a tree is perfect or not
 *
 *@tree: Tree to check if it is perfect or not
 *
 *Return: 0 if is not a perfect or height of the perfect tree
 */

int perfect_tree(const binary_tree_t *tree)
{
	int left_tree = 0, right_tree = 0;

	if (tree->left && tree->right)
	{
		left_tree = 1 + perfect_tree(tree->left);
		right_tree = 1 + perfect_tree(tree->right);
		if (right_tree == left_tree && right_tree != 0 && left_tree != 0)
			return (right_tree);
		return (0);
	}
	else if (!tree->left && !tree->right)
	{
		return (1);
	}
	else
	{
		return (0);
	}
}

/**
 *binary_tree_is_perfect - Checks the perfectness of a tree
 *
 *@tree: Tree to check if it is perfect
 *
 *Return: 1 if tree is perfect or 0 if not
 */

int binary_tree_is_perfect(const binary_tree_t *tree)
{
	int status = 0;

	if (tree == NULL)
	{
		return (0);
	}
	else
	{
		status = perfect_tree(tree);
		if (status != 0)
		{
			return (1);
		}
		return (0);
	}
}
