#include "binary_trees.h"

/**
 * binary_tree_rotate_left - Executes a left-rotation operation
 * on a binary tree.
 *
 * @tree: The pointer to the root node of the tree to rotate.
 *
 * Return: The pointer to the new root node of the tree once rotated.
 */
binary_tree_t *binary_tree_rotate_left(binary_tree_t *tree)
{

	binary_tree_t *dev_pvt, *dev_tmp;

	if (tree == NULL || tree->right == NULL)
		return (NULL);

	dev_pvt = tree->right;
	dev_tmp = dev_pvt->left;
	dev_pvt->left = tree;
	tree->right = dev_tmp;
	if (dev_tmp != NULL)
		dev_tmp->parent = tree;
	dev_tmp = tree->parent;
	tree->parent = dev_pvt;
	dev_pvt->parent = dev_tmp;
	if (dev_tmp != NULL)
	{
		if (dev_tmp->left == tree)
			dev_tmp->left = dev_pvt;
		else
			dev_tmp->right = dev_pvt;
	}

	return (dev_pvt);
}
