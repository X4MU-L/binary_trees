#include "binary_trees.h"

/**
 * binary_tree_rotate_right - rotates a binary tree from a node to the right
 * @tree: the binary tree to perform the rotation on
 * Return: on success - the pointer to the new root node.
 *         on failure - NULL
 */
binary_tree_t *binary_tree_rotate_right(binary_tree_t *tree)
{
	binary_tree_t *new_root, *tmp;

	if (!tree || !tree->left)
		return (tree);

	new_root = tree->left;
	tmp = new_root->right;

	tree->left = tmp;
	new_root->right = tree;
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
