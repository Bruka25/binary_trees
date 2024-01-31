#include "binary_trees.h"

size_t bin_tree_depth(const binary_tree_t *tree);

/**
 *binary_tree_ancestor - Function that finds the lowest common
 *                       ancestors of two nodes
 *
 *@first: Pointer to the first node
 *@second: Pointer to the second node
 *
 *Return: NULL if no ancestor is found or pointer to the
 *        lowest common ancestor
 */

binary_tree_t *binary_trees_ancestor(const binary_tree_t *first,
		const binary_tree_t *second)
{
	int depth_first, depth_second;

	if (first == NULL || second == NULL)
		return (NULL);
	if (first->n == second->n)
		return ((binary_tree_t *)first);

	depth_first = bin_tree_depth(first);
	depth_second = bin_tree_depth(second);
	if (depth_first > depth_second)
	{
		while (depth_first > depth_second)
		{
			first = first->parent;
			if (first == NULL)
				return (NULL);
			depth_first = bin_tree_depth(first);
		}
	}
	else if (depth_second > depth_first)
	{
		while (depth_second > depth_first)
		{
			second = second->parent;
			if (second == NULL)
				return (NULL);
			depth_second = bin_tree_depth(second);
		}
	}

	while (first && second)
	{
		if (first->n == second->n)
			return ((binary_tree_t *)first);
		first = first->parent;
		second = second->parent;
	}

	return (NULL);
}

/**
 *bin_tree_depth - Function that measures the depth of a node
 *
 *@tree: Pointer to the node to measure the depth
 *
 *Return: If tree is NULL 0 or or size of the depth
 */

size_t bin_tree_depth(const binary_tree_t *tree)
{
	size_t depth = 0;

	if (tree == NULL)
		return (0);

	while (tree->parent != NULL)
	{
		tree = tree->parent;
		depth++;
	}

	return (depth);
}
