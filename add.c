#include "monty.h"

/**
 * fadd - adds top 2 stack
 * @stack: pointer
 * @line_number: line number
 */

void fadd(stack_t **stack, unsigned int line_number)
{
	if (*stack == NULL || !((*stack)->next))
	{
		fprintf(stderr, "L%d: can't add, stack too short", line_number);
		free(globs.linecontent);
		free_stack(*stack);
		exit(EXIT_FAILURE);
	}

	(*stack)->next->n += (*stack)->n;
	fpop(stack, line_number);
}
