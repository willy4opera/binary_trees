#include "binary_trees.h"

int binary_tree_is_complete(const binary_tree_t *tree);
levelorder_queue_t *create_node(binary_tree_t *node);
void free_queue(levelorder_queue_t *head);
void push(binary_tree_t *node, levelorder_queue_t *head,
		levelorder_queue_t **tail);
void pop(levelorder_queue_t **head);

/**
 * binary_tree_is_complete - Verify binary tree completeness.
 *
 * @tree: The pointer to the root node of the tree to check.
 *
 * Return: 0 if tree is NULL.
 */
int binary_tree_is_complete(const binary_tree_t *tree)
{

	levelorder_queue_t *dev_HD, *dev_tail;
	unsigned char dev_flag = 0;

	if (tree == NULL)
		return (0);

	dev_HD = dev_tail = create_node((binary_tree_t *)tree);
	if (dev_HD == NULL)
		exit(1);

	while (dev_HD != NULL)
	{
		if (dev_HD->node->left != NULL)
		{
			if (dev_flag == 1)
			{
				free_queue(dev_HD);
				return (0);
			}
			push(dev_HD->node->left, dev_HD, &dev_tail);
		}
		else
			dev_flag = 1;
		if (dev_HD->node->right != NULL)
		{
			if (dev_flag == 1)
			{
				free_queue(dev_HD);
				return (0);
			}
			push(dev_HD->node->right, dev_HD, &dev_tail);
		}
		else
			dev_flag = 1;
		pop(&dev_HD);
	}
	return (1);
}

/**
 * create_node - Develop a new levelorder_queue_t node.
 *
 * @node: The binary tree node for the new node to contain.
 *
 * Return: If an error occurs, NULL.
 *         Otherwise, a pointer to the new node.
 */
levelorder_queue_t *create_node(binary_tree_t *node)
{
	levelorder_queue_t *dev_nw;

	dev_nw = malloc(sizeof(levelorder_queue_t));
	if (dev_nw == NULL)
		return (NULL);

	dev_nw->node = node;
	dev_nw->next = NULL;

	return (dev_nw);
}

/**
 * free_queue - Frees a levelorder_queue_t queue.
 *
 * @head: A pointer to the head of the queue.
 */
void free_queue(levelorder_queue_t *head)
{
	levelorder_queue_t *dev_temp;

	while (head != NULL)
	{
		dev_temp = head->next;
		free(head);
		head = dev_temp;
	}
}

/**
 * push - Pushes a node to the back of a levelorder_queue_t queue.
 *
 * @node: The binary tree node to print and push.
 * @head: A double pointer to the head of the queue.
 * @tail: A double pointer to the tail of the queue.
 *
 * Description: Upon malloc failure, exits with a status code of 1.
 */
void push(binary_tree_t *node, levelorder_queue_t *head,
		levelorder_queue_t **tail)
{
	levelorder_queue_t *dev_nw;

	dev_nw = create_node(node);
	if (dev_nw == NULL)
	{
		free_queue(head);
		exit(1);
	}
	(*tail)->next = dev_nw;
	*tail = dev_nw;
}

/**
 * pop - Pops the head of a levelorder_queue_t queue.
 *
 * @head: A double pointer to the head of the queue.
 */
void pop(levelorder_queue_t **head)
{
	levelorder_queue_t *dev_temp;

	dev_temp = (*head)->next;
	free(*head);
	*head = dev_temp;
}
