#include "monty.h"

/**
 * fpush - Add node to stack
 * @top: Element at the top of the stack
 * @line_number: constant int value in the structure
 *
 * Return: void
 */
void fpush(stack_t **top, unsigned int line_number)
{
	stack_t *new_node;

	new_node = malloc(sizeof(stack_t));
	if (new_node == NULL)
	{
		fprintf(stderr, "Error: malloc failed");
		free_exit(*top);
		exit(EXIT_FAILURE);
	}
	new_node->n = globs.data;
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

/**
 * fpall - Prints the elements of a stack
 * @top: element at the top of the stack
 * @line_number: constant int value in the structure
 *
 * Return: void
 */
void fpall(stack_t **top, unsigned int line_number)
{
	stack_t *current = *top;

	(void)line_number;
	while (current != NULL)
	{
		printf("%d\n", current->n);
		current = current->next;
	}
}

/**
 * fpint - prints the top
 * @stack: The pointer to the stack list
 * @line_number: The current working line number of a Monty bytecodes file
 */

void fpint(stack_t **stack, unsigned int line_number)
{
	stack_t *temp = *stack;

	if (!temp)
	{
		fprintf(stderr, "L%d: can't pint, stack empty", line_number);
		free_exit(*stack);
		exit(EXIT_FAILURE);
	}
	printf("%d\n", temp->n);
}
