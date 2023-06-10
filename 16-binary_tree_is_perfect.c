#include "binary_trees.h"

/**
 * binary_tree_height - get the height of a binary tree from a node
 * @tree: pointer to a binary tree node
 * Return: height of @tree
 */

size_t tree_height(const binary_tree_t *tree)
{
	size_t left_sum, right_sum;

	if (!tree)
		return (0);

	left_sum = tree_height(tree->left);
	right_sum = tree_height(tree->right);

	return ((left_sum >= right_sum ? left_sum : right_sum) + 1);
}


/**
 * binary_tree_is_perfect - checks if a binary tree is perfect
 * @tree: the node from which to check if perfect
 * Return: 1 if perfect 0 if not or @tree is NULL
 */

int binary_tree_is_perfect(const binary_tree_t *tree)
{
	size_t left_len;

	if (!tree)
		return (0);

	left_len = tree_height(tree->left);

	return (((tree_height(tree) - 1) == left_len) &&
		left_len == tree_height(tree->right));
}
