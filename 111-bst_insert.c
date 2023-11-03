#include "binary_trees.h"

/**
 * bst_insert - Inserts a value in a Binary Search Tree.
 *
 * @tree: The double pointer to the root node of the BST to insert the value.
 * @value: The value to store in the node to be inserted.
 *
 * Return: A pointer to the created node, or NULL on failure.
 */
bst_t *bst_insert(bst_t **tree, int value)
{
	bst_t *instate, *dev_nw;

	if (tree != NULL)
	{
		instate = *tree;
		if (instate == NULL)
		{
			dev_nw = binary_tree_node(instate, value);
			if (dev_nw == NULL)
				return (NULL);
			return (*tree = dev_nw);
		}
		if (value < instate->n)
		{
			if (instate->left != NULL)
				return (bst_insert(&instate->left, value));
			dev_nw = binary_tree_node(instate, value);
			if (dev_nw == NULL)
				return (NULL);
			return (instate->left = dev_nw);
		}
		if (value > instate->n)
		{
			if (instate->right != NULL)
				return (bst_insert(&instate->right, value));
			dev_nw = binary_tree_node(instate, value);
			if (dev_nw == NULL)
				return (NULL);
			return (instate->right = dev_nw);
		}
	}

	return (NULL);
}
