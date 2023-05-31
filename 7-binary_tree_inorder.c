#include "binary_trees.h"

/**
 * binary_tree_inorder - tranverse and print the values of a binary tree
 * in order
 * @tree: a binary tree node
 * @func: function pointer that takes in int as arg
 * Return: void
 */



void binary_tree_inorder(const binary_tree_t *tree, void (*func)(int))
{
	if (!tree || !func)
		return;

	binary_tree_inorder(tree->left, func);
	func(tree->n);
	binary_tree_inorder(tree->right, func);
}
