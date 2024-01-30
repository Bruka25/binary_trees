#include "binary_trees.h"

/**
 *binary_tree_insert_right - Function that inserts a node as the right-child
 *                           of parent node
 *
 *@parent: Pointer to to the node to insert the right child
 *@value: Value to store in a new node
 *
 *Return: Pointer to the created node or NULL on failure
 *        or if parent is NULL
 */

binary_tree_t *binary_tree_insert_right(binary_tree_t *parent, int value)
{
	binary_tree_t *new_child;

	if (parent == NULL)
		return (NULL);

	new_child = binary_tree_node(parent, value);

	if (new_child == NULL)
		return (NULL);

	if (parent->right != NULL)
	{
		new_child->right = parent->right;
		parent->right->parent = new_child;
	}
	parent->right = new_child;

	return (new_child);
}

