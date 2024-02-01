#include "binary_trees.h"

/**
 *array_to_bst - Function that builds binary search tree from
 *               an array
 *
 *@array: Pointer to the first element of the array
 *@size: Number of elements in the array
 *
 *Return: Pointer to the root of the node or NULL
 */


bst_t *array_to_bst(int *array, size_t size)
{
	size_t a;
	bst_t *root_node;

	if (array == NULL || size == 0)
		return (NULL);

	for (a = 0, root_node = NULL; a < size; a++)
		bst_insert(&root_node, array[a]);

	return (root_node);
}
