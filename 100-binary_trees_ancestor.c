#include "binary_trees.h"

/**
 * binary_trees_ancestor - Searches the lowest common
 * ancestor of two nodes.
 *
 * @first: The pointer to the first node.
 * @second: The pointer to the second node.
 *
 * Return: The pointer to the lowest common ancestor
 * node of the two given nodes.
 *         If no common ancestor was found, your function must return NULL.
 */
binary_tree_t *binary_trees_ancestor(const binary_tree_t *first,
		const binary_tree_t *second)
{
	binary_tree_t *num_x, *v_pop;

	if (!first || !second)
		return (NULL);
	if (first == second)
		return ((binary_tree_t *)first);

	num_x = first->parent, v_pop = second->parent;
	if (first == v_pop || !num_x || (!num_x->parent && v_pop))
		return (binary_trees_ancestor(first, v_pop));
	else if (num_x == second || !v_pop || (!v_pop->parent && num_x))
		return (binary_trees_ancestor(num_x, second));

	return (binary_trees_ancestor(num_x, v_pop));
}
