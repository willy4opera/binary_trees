#include "binary_trees.h"

/**
 * binary_tree_rotate_right - Execute a right-rotation
 * operation on a binary tree.
 *
 * @tree: The pointer to the root node of the tree to rotate.
 *
 * Return: A pointer to the new root node of the tree once rotated.
 */
binary_tree_t *binary_tree_rotate_right(binary_tree_t *tree)
{
	binary_tree_t *dv_pvot, *dev_tmp;

	if (tree == NULL || tree->left == NULL)
		return (NULL);

	dv_pvot = tree->left;
	dev_tmp = dv_pvot->right;
	dv_pvot->right = tree;
	tree->left = dev_tmp;
	if (dev_tmp != NULL)
		dev_tmp->parent = tree;
	dev_tmp = tree->parent;
	tree->parent = dv_pvot;
	dv_pvot->parent = dev_tmp;
	if (dev_tmp != NULL)
	{
		if (dev_tmp->left == tree)
			dev_tmp->left = dv_pvot;
		else
			dev_tmp->right = dv_pvot;
	}

	return (dv_pvot);
}
