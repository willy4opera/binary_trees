#include "binary_trees.h"

/**
 * binary_tree_insert_left - Inserts a node as the left-child of another node.
 *
 * @parent: A pointer to the node to insert the left child in.
 * @value: The value to store the new node.
 *
 * Return: A pointer to the created node, NULL on failure.
 */
binary_tree_t *binary_tree_insert_left(binary_tree_t *parent, int value)
{
	binary_tree_t *var;

	if (parent == NULL)
		return (NULL);

	var = binary_tree_node(parent, value);
	if (var == NULL)
		return (NULL);

	if (parent->left != NULL)
	{
		var->left = parent->left;
		parent->left->parent = var;
	}
	parent->left = var;

	return (var);
}
