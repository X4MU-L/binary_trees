#include "binary_trees.h"

/**
 * binary_tree_preorder - tranverse and print the values of a binary tree
 * in order
 * @tree: a binary tree node
 * @func: function pointer that takes in int as arg
 * Return: void
 */



void binary_tree_preorder(const binary_tree_t *tree, void (*func)(int))
{
	if (!tree || !func)
		return;

	func(tree->n);
	binary_tree_preorder(tree->left, func);
	binary_tree_preorder(tree->right, func);
}
