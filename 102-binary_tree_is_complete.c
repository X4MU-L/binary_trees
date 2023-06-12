#include "binary_trees.h"

/**
 * count_nodes - counts the number of nodes in a binary tree
 * @tree: pointer to binary tree
 * Return: number of nodes in @tree
 */
int count_nodes(const binary_tree_t *tree)
{
	if (!tree)
		return (0);

	return (1 + count_nodes(tree->left) + count_nodes(tree->right));
}

/**
 * check_complete - checks if a binary tree is a complete tree
 * @tree: pointer to binary tree
 * @index: index of binary node
 * @num_of_nodes: number of nodes in @tree
 * Return: 1 if a complete binary tree else 0
 */
int check_complete(const binary_tree_t *tree, int index, int num_of_nodes)
{
	if (!tree)
		return (1);

	if (index >= num_of_nodes)
		return (0);

	return (check_complete(tree->left, 2 * index + 1, num_of_nodes)
		&& check_complete(tree->right, 2 * index + 2, num_of_nodes));
}

/**
 * binary_tree_is_complete - checks if a binary tree is a complete
 * binary tree
 * @tree: pointer to binary tree
 * Return: 1 if a complete binary tree  else 0
 */
int binary_tree_is_complete(const binary_tree_t *tree)
{
	int node_count;

	if (!tree)
		return (0);
	node_count = count_nodes(tree);
	return (check_complete(tree, 0, node_count));
}
