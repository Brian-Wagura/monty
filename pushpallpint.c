#include "monty.h"

/**
 * fpush - Add node to stack
 * @top: Element at the top of the stack
 * @line_number: line number
 *
 * Return: void
 */
void fpush(stack_t **top, unsigned int line_number)
{
	int n;
	char *endptr;

	if (globs.arg)
	{
		n = strtol(globs.arg, &endptr, 10);
		if (*endptr != '\0')
		{
			fprintf(stderr, "L%d: usage: push integer\n", line_number);
			exit(EXIT_FAILURE);
		}
		else
		{
			fprintf(stderr, "L%d: usage: push integer\n", line_number);
			exit(EXIT_FAILURE);
		}

		if (globs.lifi == 0)
		{
			addnode(top, n);
		}
		else
		{
			addqueue(top, n);
		}
	}
}

/**
 * fpall - Prints the elements of a stack
 * @top: element at the top of the stack
 * @line_number: constant int value in the structure
 *
 * Return: void
 */
void fpall(stack_t **top, __attribute__((unused)) unsigned int line_number)
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
	if (*stack == NULL)
	{
		fprintf(stderr, "L%d: can't pint, stack empty", line_number);
		fclose(globs.fm);
		free(globs.linecontent);
		free_stack(*stack);
		exit(EXIT_FAILURE);
	}
	printf("%d\n", (*stack)->n);
}
