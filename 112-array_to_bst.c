#include "binary_trees.h"

/**
 * array_to_bst - constructs a Binary Search Tree from an array.
 *
 * @array: The pointer to the first element of the array to be converted.
 * @size: The number of element in the array
 *
 * Return: A pointer to the root node of the created BST, or NULL on failure.
 */
bst_t *array_to_bst(int *array, size_t size)
{
	bst_t *dev_tree = NULL;
	size_t idx, jdx;

	if (array == NULL)
		return (NULL);

	for (idx = 0; idx < size; idx++)
	{
		for (jdx = 0; jdx < idx; jdx++)
		{
			if (array[jdx] == array[idx])
				break;
		}
		if (jdx == idx)
		{
			if (bst_insert(&dev_tree, array[idx]) == NULL)
				return (NULL);
		}
	}

	return (dev_tree);
}
