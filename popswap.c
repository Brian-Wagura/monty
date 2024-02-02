#include "monty.h"

/**
 * fpop - removes top item from the stack
 * @stack: stack
 * @line_number: The current working line number of a Monty bytecodes file
 */
void fpop(stack_t **stack, unsigned int line_number)
{
	stack_t *tmp;

	if (*stack == NULL)
	{
		fprintf(stderr, "L%u: can't pop an empty stack\n", line_number);
		fclose(globs.fm);
		free(globs.linecontent);
		free_stack(*stack);
		exit(EXIT_FAILURE);
	}
	tmp = *stack;
	*stack = tmp->next;
	free(tmp);
}

/**
 * fswap - adds the top two elements of the stack
 * @head: stack head
 * @line_number: line number
 */
void fswap(stack_t **head, unsigned int line_number)
{
	int temp;

	if (*head == NULL || (*head)->next == NULL)
	{
		fprintf(stderr, "L%d: can't swap, stack too short\n");
		exit(EXIT_FAILURE);
	}

	temp = (*head)->n;
	(*head)->n = (*head)->next->n;
	(*head)->next->n = temp;
}
