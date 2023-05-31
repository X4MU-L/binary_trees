#include "binary_trees.h"


/**
 * binary_tree_insert_left - inserts a node to the left of a binary tree
 * @parent: the parent of the new node
 * @value: the data to add
 * Return: returns pointer to new node or NULL on failure
 */

binary_tree_t *binary_tree_insert_left(binary_tree_t *parent, int value)
{
	binary_tree_t *tmp_node, *node;

	if (!parent)
		return (NULL);

	node = binary_tree_node(parent, value);
	if (!node)
		return (node);

	if (parent->left)
	{
		tmp_node = parent->left;
		parent->left = node;
		parent->left->left = tmp_node;
		parent->left->left->parent = node;

		return (node);
	}

	parent->left = node;

	return (node);
}
