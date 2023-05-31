#include "binary_trees.h"

/**
 * binary_tree_depth - get the depth of a binary tree
 * @tree: pointer to a binary tree
 * Return: depth of @tree
 */


size_t binary_tree_depth(const binary_tree_t *tree)
{

	if (!tree || !tree->parent)
		return (0);

	return (binary_tree_depth(tree->parent) + 1);
}
