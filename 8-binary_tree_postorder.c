#include "binary_trees.h"

/**
 * binary_tree_postorder - tranverse and print the values of a binary tree
 * using post order
 * @tree: a binary tree node
 * @func: function pointer that takes in int as arg
 * Return: void
 */



void binary_tree_postorder(const binary_tree_t *tree, void (*func)(int))
{
	if (!tree || !func)
		return;

	binary_tree_postorder(tree->left, func);
	binary_tree_postorder(tree->right, func);
	func(tree->n);
}
