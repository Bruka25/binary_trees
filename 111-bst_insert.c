#include "binary_trees.h"

bst_t *bst_inserter(bst_t *node, int value);

/**
 *bst_insert - Function that inserts a value in BST
 *
 *@tree: Double pointer to the BST to insert
 *@value: Value to be inserted into the node
 *
 *Return: The tree with the inserted value
 */

bst_t *bst_insert(bst_t **tree, int value)
{
	if (*tree == NULL)
	{
		*tree = binary_tree_node(NULL, value);
		return (*tree);
	}

	return (bst_inserter(*tree, value));
}

/**
 *bst_inserter - helper function for inserting nodes into BST
 *
 *@node: pointer to current potential parent node
 *@value: value to store in new node
 *
 *Return: pointer to new node or NULL on failure
 */

bst_t *bst_inserter(bst_t *node, int value)
{
	bst_t *new_node;

	if (value > node->n)
	{
		if (node->right)
		{
			return (bst_inserter(node->right, value));
		}
		else
		{
			new_node = binary_tree_node(node, value);
			node->right = new_node;
			return (new_node);
		}
	}
	else if (value < node->n)
	{
		if (node->left)
		{
			return (bst_inserter(node->left, value));
		}
		else
		{
			new_node = binary_tree_node(node, value);
			node->left = new_node;
			return (new_node);
		}
	}

	return (NULL);
}
