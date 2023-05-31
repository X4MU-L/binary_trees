#include "binary_trees.h"

/**
 * binary_tree_height - get the height of a binary tree from a node
 * @tree: pointer to a binary tree node
 * Return: height of @tree
 */


size_t binary_tree_height(const binary_tree_t *tree)
{
	size_t left_sum, right_sum;

	if (!tree || (!tree->right && !tree->left))
		return (0);

	left_sum = binary_tree_height(tree->left);
	right_sum = binary_tree_height(tree->right);

	return ((left_sum >= right_sum ? left_sum : right_sum) + 1);
}
