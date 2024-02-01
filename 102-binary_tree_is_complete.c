#include "binary_trees.h"


order_queue_t *queue_create(binary_tree_t *node);
void free_queue(order_queue_t *head);
void queue_push(binary_tree_t *node, order_queue_t *head,
		order_queue_t **tail);

void queue_pop(order_queue_t **head);

/**
 *binary_tree_is_complete - Checks if a binary tree is complete
 *
 *@tree: Pointer to the root node of the tree to check
 *
 *Return: 0 if tree is NULL or status of the tree
 */

int binary_tree_is_complete(const binary_tree_t *tree)
{
	order_queue_t *head, *tail;
	unsigned char flag = 0;

	if (tree == NULL)
		return (0);

	head = tail = queue_create((binary_tree_t *)tree);
	if (head == NULL)
		exit(1);

	while (head != NULL)
	{
		if (head->node->left != NULL)
		{
			if (flag == 1)
			{
				free_queue(head);
				return (0);
			}
			queue_push(head->node->left, head, &tail);
		}
		else
			flag = 1;
		if (head->node->right != NULL)
		{
			if (flag == 1)
			{
				free_queue(head);
				return (0);
			}
			queue_push(head->node->right, head, &tail);
		}
		else
			flag = 1;
		queue_pop(&head);
	}
	return (1);
}

/**
 *queue_create - Creates a new order_queue_t node
 *
 *@node: The binary tree node for the new node to contain
 *
 *Return: If an error occurs, NULL.
 *        Otherwise, a pointer to the new node
 */

order_queue_t *queue_create(binary_tree_t *node)
{
	order_queue_t *new;

	new = malloc(sizeof(order_queue_t));
	if (new == NULL)
		return (NULL);

	new->node = node;
	new->next = NULL;

	return (new);
}

/**
 *free_queue - Frees a levelorder_queue_t queue
 *
 *@head: A pointer to the head of the queue
 *
 *Return: Void
 */

void free_queue(order_queue_t *head)
{
	order_queue_t *tmp;

	while (head != NULL)
	{
		tmp = head->next;
		free(head);
		head = tmp;
	}
}
/**
 *queue_push - Pushes a node to the back of queue
 *
 *@node: The binary tree node to print and push
 *@head: A double pointer to the head of the queue
 *@tail: A double pointer to the tail of the queue
 *
 *Return: Void
 */

void queue_push(binary_tree_t *node, order_queue_t *head,
		order_queue_t **tail)
{
	order_queue_t *new;

	new = queue_create(node);
	if (new == NULL)
	{
		free_queue(head);
		exit(1);
	}
	(*tail)->next = new;
	*tail = new;
}

/**
 *queue_pop - Pops the head of a levelorder_queue_t queue
 *
 *@head: A double pointer to the head of the queue
 *
 *Return: Void
 */

void queue_pop(order_queue_t **head)
{
	order_queue_t *tmp;

	tmp = (*head)->next;
	free(*head);
	*head = tmp;
}
