#include "binary_trees.h"

/**
 * binary_tree_is_leaf - We checks if a node is a leaf.
 *
 * @node: The pointer to the node we check.
 *
 * Return: 1 when node is a leaf, otherwise retun 0.
 */
int binary_tree_is_leaf(const binary_tree_t *node)
{
	if (node == NULL || node->left != NULL || node->right != NULL)
		return (0);

	return (1);
}
