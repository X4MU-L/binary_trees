#include "binary_trees.h"


/**
 * binary_tree_insert_right - inserts a node to the right of a binary tree
 * @parent: the parent of the new node
 * @value: the data to add
 * Return: returns pointer to new node or NULL on failure
 */

binary_tree_t *binary_tree_insert_right(binary_tree_t *parent, int value)
{
	binary_tree_t *tmp_node, *node;

	node = binary_tree_node(parent, value);
	if (!node)
		return (node);

	if (!parent)
		return (node);
	else if (parent->right)
	{
		tmp_node = parent->right;
		parent->right = node;
		parent->right->right = tmp_node;
		parent->right->right->parent = node;

		return (node);
	}

	parent->right = node;

	return (node);
}
