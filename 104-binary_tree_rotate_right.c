#include "binary_trees.h"


/**
 *binary_rotate_right - Function that performs a left rotation on a
 *                     binary tree
 *
 *@tree: Pointer to the root node to rotate
 *
 *Return: Pointer to the root node after rotated
 */


binary_tree_t *binary_tree_rotate_right(binary_tree_t *tree)
{
	binary_tree_t *tree_pivot, *temp;

	if (tree == NULL || tree->left == NULL)
		return (NULL);

	tree_pivot = tree->left;
	temp = tree_pivot->right;
	tree_pivot->right = tree;
	tree->left = temp;
	if (temp != NULL)
		temp->parent = tree;
	temp = tree->parent;
	tree->parent = tree_pivot;
	tree_pivot->parent = tmp;
	if (temp != NULL)
	{
		if (temp->left == tree)
			temp->left = tree_pivot;
		else
			temp->right = tree_pivot;
	}

	return (tree_pivot);
}
