#include "binary_trees.h"

/**
 *binary_tree_rotate_left - Function that performs a left rotation on a
 *                     binary tree
 *
 *@tree: Pointer to the root node to rotate
 *
 *Return: Pointer to the root node after rotated
 */

binary_tree_t *binary_tree_rotate_left(binary_tree_t *tree)
{
	binary_tree_t *temp, *new_root;

	temp = NULL;
	if (tree == NULL)
		return (NULL);

	if (tree->right->left != NULL)
		temp = tree->right->left;

	if (tree->right == NULL)
		return (tree);

	new_root = tree->right;
	tree->right->left = tree;
	tree->parent = tree->right;
	tree->right->parent = NULL;
	tree->right = temp;
	if (temp != NULL)
		temp->parent = tree;

	return (new_root);
}
