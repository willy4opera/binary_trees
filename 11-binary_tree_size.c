#include "binary_trees.h"

/**
 * binary_tree_size - Reads the size of a binary tree.
 *
 * @tree: The pointer to the root node of the tree to measure the size.
 *
 * Return: 0 if tree is NULL.
 */
size_t binary_tree_size(const binary_tree_t *tree)
{
	size_t dev_size = 0;

	if (tree)
	{
		dev_size += 1;
		dev_size += binary_tree_size(tree->left);
		dev_size += binary_tree_size(tree->right);
	}

	return (dev_size);
}
