#include "binary_trees.h"

/**
 * binary_tree_insert_right - Inserts a node as the right-child of a node.
 *
 * @parent: A pointer to the node to insert the right-child in.
 * @value: The value to store in the new node.
 *
 * Return: A pointer to the created node, NULL on failure or if parent is NULL.
 */
binary_tree_t *binary_tree_insert_right(binary_tree_t *parent, int value)
{
	binary_tree_t *dev_var;

	if (parent == NULL)
		return (NULL);

	dev_var = binary_tree_node(parent, value);
	if (dev_var == NULL)
		return (NULL);

	if (parent->right != NULL)
	{
		dev_var->right = parent->right;
		parent->right->parent = dev_var;
	}
	parent->right = dev_var;

	return (dev_var);
}
