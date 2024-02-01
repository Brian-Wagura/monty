#include "monty.h"

/**
 * fpush - Add node to list
 * @top: Element at the top of the stack
 * @line_number: constant int value in the structure
 *
 * Return: void
 */
void fpush(stack_t **top, unsigned int line_number)
{
	int num;
	stack_t *new_node;

	new_node = malloc(sizeof(stack_t));
	if (new_node == NULL)
		malloc_error();
	new_node->n = num;
	new_node->prev = NULL;
	if (*top == NULL)
	{
		new_node->next = NULL;
	}
	else
	{
		new_node->next = *top;
		(*top)->prev = new_node;
	}
	*top = new_node;
}
