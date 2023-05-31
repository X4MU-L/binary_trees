#include "binary_trees.h"

/**
 * binary_tree_leaves - count the leave nodes of a binary tree from a node
 * @tree: pointer to a binary tree node
 * Return: height of @tree
 */


size_t binary_tree_leaves(const binary_tree_t *tree)
{
	size_t left_sum, right_sum;

	if (!tree)
		return (0);
	else if (!tree->left && !tree->right)
		return (1);

	left_sum = binary_tree_leaves(tree->left);
	right_sum = binary_tree_leaves(tree->right);

	return (left_sum +  right_sum);
}
