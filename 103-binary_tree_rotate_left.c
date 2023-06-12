#include "binary_trees.h"

/**
 * binary_tree_rotate_left - rotates a binary tree from a node to the left
 * @tree: the binary tree to perform the rotation on
 * Return: on success - the pointer to the new root node.
 *         on failure - NULL
 */
binary_tree_t *binary_tree_rotate_left(binary_tree_t *tree)
{
	binary_tree_t *new_root, *tmp;

	if (!tree || !tree->right)
		return (tree);

	new_root = tree->right;
	tmp = new_root->left;

	tree->right = tmp;
	new_root->left = tree;
	if (tmp)
		tmp->parent = tree;
	tmp = tree->parent;
	tree->parent = new_root;
	new_root->parent = tmp;
	if (tmp)
	{
		if (tmp->right == tree)
			tmp->right = new_root;
		else
			tmp->left = new_root;
	}
	return (new_root);
}
