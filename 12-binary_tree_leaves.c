#include "binary_trees.h"

/**
 * binary_tree_leaves - Counts the leaves in a binary tree.
 *
 * @tree: The pointer to the root node of
 * the tree to count the number of leaves.
 *
 * Return: 0 if tree is NULL.
 */
size_t binary_tree_leaves(const binary_tree_t *tree)
{
	size_t d_leavs = 0;

	if (tree)
	{
		d_leavs += (!tree->left && !tree->right) ? 1 : 0;
		d_leavs += binary_tree_leaves(tree->left);
		d_leavs += binary_tree_leaves(tree->right);
	}

	return (d_leavs);
}
