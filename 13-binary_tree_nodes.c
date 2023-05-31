#include "binary_trees.h"

/**
 * binary_tree_nodes - count the nodes with at least one child
 * in binary tree from a node
 * @tree: pointer to a binary tree node
 * Return: height of @tree
 */


size_t binary_tree_nodes(const binary_tree_t *tree)
{
	if (!tree || (!tree->left && !tree->right))
		return (0);

	return (binary_tree_nodes(tree->left) +
		binary_tree_nodes(tree->right) +
		1);
}
