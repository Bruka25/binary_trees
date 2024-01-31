#include "binary_trees.h"

/**
 *binary_tree_sibling - Function that finds sibling of
 *                      a node
 *
 *@node: Pointer to the node to find the sibling
 *
 *Return: NULL if the parent is NULL or if node has no
 *        sibling or node is NULL, else pointer to the
 *        sibling node
 */

binary_tree_t *binary_tree_sibling(binary_tree_t *node)
{
	if (node == NULL || node->parent == NULL ||
	    node->parent->left == NULL || node->parent->right == NULL)
		return (NULL);

	if (node->parent->left->n == node->n)
		return (node->parent->right);

	return (node->parent->left);
}
