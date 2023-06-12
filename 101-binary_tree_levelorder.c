#include "binary_trees.h"

/**
 * is_empty - checks if a queue is NULL
 * @queue: pointer to a queue
 * Return: 1 if NULL else 0
 */
int is_empty(queue_t *queue)
{
	return (queue == NULL);
}

/**
 * create_queue - creates a new
 * Return: a pointer to a new queue or NULL on failure
 */
queue_t *create_queue(void)
{
	queue_t *queue;

	queue = malloc(sizeof(queue_t));
	if (!queue)
		return (NULL);
	queue->node = NULL;
	queue->next = NULL;
	return (queue);
}
/**
 * push_to_queue - adds a queue to the queue
 * @node: node to add to new queue
 * @queue: pointer to a queue pointer
 * Return: void
 */
void push_to_queue(queue_t **queue, binary_tree_t *node)
{
	queue_t *temp = *queue, *new;

	if (!*queue || !node)
		return;

	if (!(*queue)->node)
	{
		(*queue)->node = node;
		return;
	}
	new = create_queue();
	if (!new)
		return;
	while (temp->next)
		temp = temp->next;

	new->node = node;
	temp->next = new;
}

/**
 * pop_queue - pops a queue from the queue
 * @queue: pointer to a queue pointer
 * Return: void
 */
void pop_queue(queue_t **queue)
{
	queue_t *temp;

	if (is_empty(*queue))
		return;

	temp = *queue;
	*queue = (*queue)->next;
	free(temp);
}

/**
 * binary_tree_levelorder - tranverse and print from a binary tree
 * in level order using queue
 * @tree: pointer the binary tree
 * @func: a function pointer to print int
 * Return: void
 */

void binary_tree_levelorder(const binary_tree_t *tree, void (*func)(int))
{
	queue_t *queue;
	binary_tree_t *current;

	if (!tree || !func)
		return;

	queue = create_queue();
	if (!queue)
		return;
	push_to_queue(&queue, (binary_tree_t *) tree);

	while (!is_empty(queue))
	{
		current = queue->node;
		func(current->n);

		if (current->left)
			push_to_queue(&queue, current->left);
		if (current->right)
			push_to_queue(&queue, current->right);
		pop_queue(&queue);
	}
	free(queue);
}
