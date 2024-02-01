#include "binary_trees.h"

avl_t *half_tree_sort(avl_t *parent, int *array, int first, int last);

/**
 *sorted_array_to_avl - Function that builds avl tree from
 *                      a sorted array
 *
 *@array: Pointer to the first element in the array
 *@size: Number of elements in the array
 *
 *Return: Pointer to the root node of the created AVL tree or
 *        NULL on failure
 */

avl_t *sorted_array_to_avl(int *array, size_t size)
{
	if (array == NULL || size == 0)
		return (NULL);
	return (half_tree_sort(NULL, array, 0, ((int)(size)) - 1));
}


/**
 *half_tree_sort - create the tree using the half element of the array
 *
 *@parent: parent of the node to create
 *@array: sorted array
 *@first: position where the array starts
 *@last: position where the array ends
 *
 *Return: the sorted tree
 */

avl_t *half_tree_sort(avl_t *parent, int *array, int first, int last)
{
	avl_t *tree_root;
	binary_tree_t *aux;
	int mid_node = 0;

	if (first <= last)
	{
		mid_node = (first + last) / 2;
		aux = binary_tree_node((binary_tree_t *)parent, array[mid_node]);
		if (aux == NULL)
			return (NULL);
		tree_root = (avl_t *)aux;
		tree_root->left = half_tree_sort(tree_root, array, first, mid_node - 1);
		tree_root->right = half_tree_sort(tree_root, array, mid_node + 1, last);
		return (tree_root);
	}
	return (NULL);
}
