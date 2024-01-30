#include "binary_trees.h"

/**
 *binary_tree_insert_left - Function that inserts node as a left child of
 *                          another node
 *
 *@parent: Pointer to the node to insert the left-child
 *@value: Value to store in the new node
 *
 *Return: Pointer to the created node or NULL on failure
 *        or if the parent is NULL
 */


binary_tree_t *binary_tree_insert_left(binary_tree_t *parent, int value)
{
	binary_tree_t *new_child;

	if (parent == NULL)
		return (NULL);

	new_child = binary_tree_node(parent, value);

	if (new_child == NULL)
		return (NULL);

	if (parent->left != NULL)
	{
		new_child->left = parent->left;
		parent->left->parent = new_child;
	}
	parent->left = new_child;

	return (new_child);
}
