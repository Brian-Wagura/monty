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

	while (stack != NULL)
	{
		temp = stack->next;
		free(stack);
		stack = temp;
	}
}

/**
 * free_exit - Frees all possible allocs before exiting the program
 * @stack: ptr to a stack
 * Return: void
 */
void free_exit(stack_t *stack)
{
	fclose(globs.fm);

	if (globs.lineptr != NULL)
		free(globs.lineptr);
	free_stack(stack);
}
