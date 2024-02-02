#include "monty.h"

/**
 * free_stack - free a stack with single pointer reference
 * @stack: pointer to a linked list
 *
 * Return: void
 */
void free_stack(stack_t *stack)
{
	stack_t *temp;

	temp = stack;
	while (stack)
	{
		temp = stack->next;
		free(stack);
		stack = temp;
	}
}
