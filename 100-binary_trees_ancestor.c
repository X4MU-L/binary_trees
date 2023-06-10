#include "binary_trees.h"

/**
 * binary_trees_ancestor - gets the common lowest ancestor of two nodes
 * @first: first node
 * @second: second node
 * Return: returns the lowest common ancestor or NULL if non
 */
binary_tree_t *binary_trees_ancestor(const binary_tree_t *first,
				     const binary_tree_t *second)
{
	if (!first || !second || !second->parent || !first->parent)
		return (NULL);

	else if (first == second)
		return ((binary_tree_t *)first);
	else if (second->parent == first)
		return ((binary_tree_t *)first);
	else if (first->parent == second)
		return ((binary_tree_t *)second);
	else if (first->parent == second->parent)
		return (first->parent);
	else if (second->parent->parent == first->parent)
		return (first->parent);
	else if (first->parent->parent == second->parent)
		return (second->parent);

	return (binary_trees_ancestor(first->parent, second->parent));
}
