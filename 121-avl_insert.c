#include "binary_trees.h"

int balance_factor(const binary_tree_t *tree);
avl_t *insert_recursively(avl_t **tree, avl_t *parent,
		avl_t **new, int value);

size_t avl_tree_height(const binary_tree_t *tree);

/**
 *avl_insert - Function that inserts a value into an AVL
 *             tree
 *
 *@tree: Double pointer to the root node of AVL tree
 *@value: the value to be inserted into the avl
 *
 *Return: Null on failure or pointer to the created node
 */

avl_t *avl_insert(avl_t **tree, int value)
{
	avl_t *new_node = NULL;

	if (tree == NULL)
		return (NULL);
	if (*tree == NULL)
	{
		*tree = binary_tree_node(NULL, value);
		return (*tree);
	}
	insert_recursively(tree, *tree, &new_node, value);
	return (new_node);
}


/**
 *avl_tree_height - Function that measures the avl_tree_height of
 *                     a binary tree
 *
 *@tree: Pointer to the root node of the tree to measure
 *
 *Return: avl_tree_height of a tree or 0 if the tree is NULL
 */

size_t avl_tree_height(const binary_tree_t *tree)
{
	size_t left_avl_tree_height = 0;
	size_t right_avl_tree_height = 0;

	if (tree == NULL)
		return (0);

	if (tree->left != NULL)
		left_avl_tree_height = avl_tree_height(tree->left) + 1;

	if (tree->right != NULL)
		right_avl_tree_height = avl_tree_height(tree->right) + 1;

	return (left_avl_tree_height > right_avl_tree_height ?
			left_avl_tree_height : right_avl_tree_height);
}

/**
 *balance_factor - Measures the balance factor of a binary tree
 *
 *@tree: A pointer to the root node of the tree to measure the balance factor
 *
 *Return: If tree is NULL, return 0, else return balance factor
 */

int balance_factor(const binary_tree_t *tree)
{
	return (tree != NULL ? avl_tree_height(tree->left)
			- avl_tree_height(tree->right) : 0);
}

/**
 *insert_recursively - Inserts a value into an AVL tree recursively
 *
 *@tree: A double pointer to the root node of the AVL tree to insert into
 *@parent: The parent node of the current working node
 *@new: A double pointer to store the new node
 *@value: The value to insert into the AVL tree
 *
 *Return: A pointer to the new root after insertion, or NULL on failure
 */

avl_t *insert_recursively(avl_t **tree, avl_t *parent,
		avl_t **new, int value)
{
	int bal_factor;

	if (*tree == NULL)
		return (*new = binary_tree_node(parent, value));

	if ((*tree)->n > value)
	{
		(*tree)->left = insert_recursively(&(*tree)->left, *tree, new, value);
		if ((*tree)->left == NULL)
			return (NULL);
	}
	else if ((*tree)->n < value)
	{
		(*tree)->right = insert_recursively(&(*tree)->right, *tree, new, value);
		if ((*tree)->right == NULL)
			return (NULL);
	}
	else
		return (*tree);

	bal_factor = balance_factor(*tree);
	if (bal_factor > 1 && (*tree)->left->n > value)
		*tree = binary_tree_rotate_right(*tree);
	else if (bal_factor < -1 && (*tree)->right->n < value)
		*tree = binary_tree_rotate_left(*tree);
	else if (bal_factor > 1 && (*tree)->left->n < value)
	{
		(*tree)->left = binary_tree_rotate_left((*tree)->left);
		*tree = binary_tree_rotate_right(*tree);
	}
	else if (bal_factor < -1 && (*tree)->right->n > value)
	{
		(*tree)->right = binary_tree_rotate_right((*tree)->right);
		*tree = binary_tree_rotate_left(*tree);
	}

	return (*tree);
}
