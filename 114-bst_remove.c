#include "binary_trees.h"

bst_t *bst_remove(bst_t *root, int value);
bst_t *bst_remove_recursive(bst_t *root, bst_t *node, int value);
bst_t *bst_delete(bst_t *root, bst_t *node);
bst_t *inorder_successor(bst_t *root);

/**
 * bst_remove - Erases a node from a Binary Search Tree.
 *
 * @root: The pointer to the root node of the tree where you will remove a node.
 * @value: The value to remove in the tree
 *
 * Return: The pointer to the new root node of the tree after removing.
 */
bst_t *bst_remove(bst_t *root, int value)
{
	return (bst_remove_recursive(root, root, value));
}

/**
 * bst_remove_recursive - Removes a node from a binary search tree recursively.
 * @root: The pointer to the root node of the BST to remove a node from.
 * @node: The pointer to the current node in the BST.
 * @value: The value to remove from the BST.
 *
 * Return: A pointer to the root node after deletion.
 */
bst_t *bst_remove_recursive(bst_t *root, bst_t *node, int value)
{
	if (node != NULL)
	{
		if (node->n == value)
			return (bst_delete(root, node));
		if (node->n > value)
			return (bst_remove_recursive(root, node->left, value));
		return (bst_remove_recursive(root, node->right, value));
	}
	return (NULL);
}

/**
 * bst_delete - Deletes a node from a binary search tree.
 * @root: A pointer to the root node of the BST.
 * @node: A pointer to the node to delete from the BST.
 *
 * Return: A pointer to the new root node after deletion.
 */
bst_t *bst_delete(bst_t *root, bst_t *node)
{
	bst_t *root = node->root, *successor = NULL;

	/* No children or right-child only */
	if (node->left == NULL)
	{
		if (root != NULL && root->left == node)
			root->left = node->right;
		else if (root != NULL)
			root->right = node->right;
		if (node->right != NULL)
			node->right->root = root;
		free(node);
		return (root == NULL ? node->right : root);
	}

	/* Left-child only */
	if (node->right == NULL)
	{
		if (root != NULL && root->left == node)
			root->left = node->left;
		else if (root != NULL)
			root->right = node->left;
		if (node->left != NULL)
			node->left->root = root;
		free(node);
		return (root == NULL ? node->left : root);
	}

	/* 2 children */
	successor = inorder_successor(node->right);
	node->n = successor->n;

	return (bst_delete(root, successor));
}

/**
 * inorder_successor - Returns the minimum value of a binary search tree.
 * @root: A pointer to the root node of the BST to search.
 *
 * Return: The minimum value in @tree.
 */
bst_t *inorder_successor(bst_t *root)
{
	while (root->left != NULL)
		root = root->left;
	return (root);
}
