#include "binary_trees.h"

/**
 * binary_tree_node - Create a binary tree node.
 *
 * @parent: A pointer to the parent of the node.
 * @value: The value to be puted on the new node.
 *
 * Return: If it fails - NULL else - a pointer to the new node.
 */
binary_tree_t *binary_tree_node(binary_tree_t *parent, int value)
{
	binary_tree_t *var;

	var = malloc(sizeof(binary_tree_t));
	if (var == NULL)
		return (NULL);

	var->n = value;
	var->parent = parent;
	var->left = NULL;
	var->right = NULL;

	return (var);
}
