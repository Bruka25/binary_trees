#include "binary_trees.h"


/**
 *array_to_avl - Function that builds avl tree from an array
 *
 *@array: Pointer to the first element in the array
 *@size: Number of elements in the array
 *
 *Return: Pointer to the root node of the created AVL tree or
          NULL on failure
 */

avl_t *array_to_avl(int *array, size_t size)
{
	avl_t *root_node = NULL;
	size_t i, j;

	if (array == NULL)
		return (NULL);

	for (i = 0; i < size; i++)
	{
		for (j = 0; j < i; j++)
		{
			if (array[j] == array[i])
				break;
		}
		if (j == i)
		{
			if (avl_insert(&root_node, array[i]) == NULL)
				return (NULL);
		}
	}

	return (root_node);
}
