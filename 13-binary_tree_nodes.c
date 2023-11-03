#include "binary_trees.h"

/**
 * binary_tree_nodes - number the nodes
 * with at least 1 child in a binary tree.
 *
 * @tree: The pointer to the root node of
 * the tree to count the number of nodes.
 *
 * Return: 0 if tree is NULL.
 */
size_t binary_tree_nodes(const binary_tree_t *tree)
{
	size_t d_nds = 0;

	if (tree)
	{
		d_nds += (tree->left || tree->right) ? 1 : 0;
		d_nds += binary_tree_nodes(tree->left);
		d_nds += binary_tree_nodes(tree->right);
	}

	return (d_nds);
}
