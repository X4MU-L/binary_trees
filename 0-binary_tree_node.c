#include "binary_trees.h"

/**
 * binary_tree_node - creates a binary tree node and returns the
 * pointer or NULL on failure
 * @parent: the parent of the new node to create
 * @value: the value of the new node
 * Return: return a pointer to a binary tree or NULL on failure
 */


binary_tree_t *binary_tree_node(binary_tree_t *parent, int value)
{
	binary_tree_t *node;

	node = malloc(sizeof(binary_tree_t));
	if (!node)
		return (NULL);
	node->parent = parent;
	node->n = value;
	node->left = NULL;
	node->right = NULL;

	return (node);
}
