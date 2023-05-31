#include "binary_trees.h"

int get_balance_height(const binary_tree_t *tree);


/**
 * binary_tree_balance - measure the balance factor of a binary tree
 * @tree: pointer to a binary tree node
 * Return: the balance factor of the tree from @tree
 */
int binary_tree_balance(const binary_tree_t *tree)
{
	if (!tree)
		return (0);

	return (get_balance_height(tree->left) -
		get_balance_height(tree->right));
}

/**
 * get_balance_height - get the balance height of a binary tree from a node
 * @tree: pointer to binary tree node
 * Return: int
 */

int get_balance_height(const binary_tree_t *tree)
{
	int left_sum, right_sum;

	if (!tree)
		return (0);

	left_sum = get_balance_height(tree->left);
	right_sum = get_balance_height(tree->right);

	return ((left_sum >= right_sum ? left_sum : right_sum) + 1);
}
