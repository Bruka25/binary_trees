#include "binary_trees.h"


bst_t *find_root(bst_t *node);

/**
 *bst_remove - Removes a node from a binary search tree
 *
 *@root: Pointer to the root node of the tree where the node
 *       will be removed
 *@value: Value to remove in a tree
 *
 *Return: Pointer to the new root node of the tree after
 *        being removed
 */

bst_t *bst_remove(bst_t *root, int value)
{
	bst_t *delete, *successor, *new_root;
	int status;

	if (root == NULL)
		return (NULL);

	delete = bst_search(root, value);
	if (delete == NULL)
		return (NULL);
	successor = NULL, status = 0;

	if (delete->right)
	{
		successor = delete->right, status = 1;
		while (successor->left)
			successor = successor->left;
	}
	else if (delete->left)
		successor = delete->left;
	if (successor == NULL)
	{
		if (delete->parent->left->n == delete->n)
			delete->parent->left = NULL;
		else
			delete->parent->right = NULL;
		new_root = find_root(delete);
		free(delete);
	}
	else if (status == 1)
	{
		delete->n = successor->n;
		new_root = find_root(successor);
		if (successor->parent->left->n == successor->n)
			successor->parent->left = NULL;
		else
			successor->parent->right = NULL;
		free(successor);
	}
	else
	{
		delete->n = successor->n;
		delete->left = delete->left->left;
		if (delete->left)
			delete->left->parent = delete;
		new_root = find_root(delete);
		free(successor);
	}
	return (new_root);
}



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


/**
 *find_root - find the root of a Binary Search Tree
 *
 *@node: node in a BST
 *
 *Return: pointer to root node, else NULL
 */

bst_t *find_root(bst_t *node)
{
	if (node == NULL)
		return (NULL);

	while (node->parent)
		node = node->parent;

	return (node);
}
