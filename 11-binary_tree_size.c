#include "binary_trees.h"

/**
 * binary_tree_size - get the height of a binary tree from a node
 * @tree: pointer to a binary tree node
 * Return: height of @tree
 */


size_t binary_tree_size(const binary_tree_t *tree)
{
	size_t left_sum, right_sum;

	if (!tree)
		return (0);

	left_sum = binary_tree_size(tree->left);
	right_sum = binary_tree_size(tree->right);

	return (left_sum + right_sum + 1);
}
