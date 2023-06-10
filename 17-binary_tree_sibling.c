#include "binary_trees.h"

/**
 * binary_tree_sibling - gets the sibling of a givin node if any
 * @node: the binary tree node to get its sibling
 * Return: the sibling node on success else NULL
 */

binary_tree_t *binary_tree_sibling(binary_tree_t *node)
{
	if (!node || !node->parent)
		return (NULL);

	if (node->parent->left == node)
		return (node->parent->right);

	return (node->parent->left);
}
