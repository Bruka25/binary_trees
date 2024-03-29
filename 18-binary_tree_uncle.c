#include "binary_trees.h"

/**
 *binary_tree_uncle - Function that finds uncle of a node
 *
 *@node: Pointer to the node to find the uncle
 *
 *Return: NULL if node is NULL, if node don't have any uncle
 *        otherwise pointer to the uncle node
 */

binary_tree_t *binary_tree_uncle(binary_tree_t *node)
{
	if (node == NULL ||
	    node->parent == NULL ||
	    node->parent->parent == NULL)
		return (NULL);

	if (node->parent->parent->left == node->parent)
		return (node->parent->parent->right);

	return (node->parent->parent->left);
}
