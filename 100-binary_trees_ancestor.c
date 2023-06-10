#include "binary_trees.h"

/**
 * find_ancestor - find the common ancestor of two nodes
 * @root: the root of the nodes
 * @first: the first node
 * @second: the second node
 * Return: the common ancestor of both nodes or NULL
 */

binary_tree_t *find_ancestor(const binary_tree_t *root,
			     const binary_tree_t *first,
			     const binary_tree_t *second)
{
	binary_tree_t *left, *right;

	if (root == first || root == second)
		return ((binary_tree_t *) root);

	if (!root || (!root->right && !root->left))
		return (NULL);

	left = find_ancestor(root->left, first, second);
	right = find_ancestor(root->right, first, second);
	if (left && right)
		return ((binary_tree_t *)root);

	return ((left == NULL) ? right : left);
}

/**
 * binary_trees_ancestor - gets the common lowest ancestor of two nodes
 * @first: first node
 * @second: second node
 * Return: returns the lowest common ancestor or NULL if non
 */
binary_tree_t *binary_trees_ancestor(const binary_tree_t *first,
				     const binary_tree_t *second)
{
	binary_tree_t *root = (binary_tree_t *) first;
	binary_tree_t *root2 = (binary_tree_t *) second;

	if (!first || !second)
		return (NULL);

	while (root->parent)
		root = root->parent;
	while (root2->parent)
		root2 = root2->parent;
	if (root != root2)
		return (NULL);

	return (find_ancestor(root, first, second));
}
