#include "binary_trees.h"

/**
 * binary_tree_is_root - checks if a node is a root node
 * @node: node to check if root node
 * Return: 0 if not left node or NULL else 1
 */
int binary_tree_is_root(const binary_tree_t *node)
{
	if (!node)
		return (0);

	return (!node->parent);
}
