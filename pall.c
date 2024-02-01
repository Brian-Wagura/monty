#include "monty.h"

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

	while (current != NULL)
	{
		printf("%d\n", current->n);
		current = current->next;
	}
}
