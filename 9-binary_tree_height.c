#include "binary_trees.h"

/**
 * binary_tree_height - Take measure of the height of a binary tree.
 *
 * @tree: The pointer to the root node of the tree to measure the height.
 *
 * Return: 0 if tree is NULL.
 */
size_t binary_tree_height(const binary_tree_t *tree)
{
	if (tree)
	{
		size_t dev_lef = 0, dev_rig = 0;

		dev_lef = tree->left ? 1 + binary_tree_height(tree->left) : 0;
		dev_rig = tree->right ? 1 + binary_tree_height(tree->right) : 0;

		return ((dev_lef > dev_rig) ? dev_lef : dev_rig);
	}

	return (0);
}
