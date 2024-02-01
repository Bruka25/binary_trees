#include "binary_trees.h"

/**
 *bst_search - Function that searches for a value in a BST
 *
 *@tree: Pointer to the root node of the tree to search
 *@value: Value to search in a tree
 *
 *Return: NULL if tree is NULL or if nothing found
 *        else pointer to the node conaining a value thats been
 *        searched
 */


bst_t *bst_search(const bst_t *tree, int value)
{
	if (tree == NULL)
		return (NULL);

	if (tree->n == value)
		return ((bst_t *)tree);

	if (value < tree->n)
		return (bst_search(tree->left, value));

	return (bst_search(tree->right, value));
}
