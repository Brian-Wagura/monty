#include "monty.h"

/**
 * fmul - multiplies the top two elements of the stack
 * @head: stack head
 * @line_number: line number
 * Return: no return
 */

void fmul(stack_t **head, unsigned int line_number)
{
	stack_t *temp;

	if (*head == NULL || (*head)->next == NULL)
	{
		fprintf(stderr, "L%d: can't mul, stack too short\n", line_number);
		fclose(globs.fm);
		free(globs.linecontent);
		free_stack(*head);
		exit(EXIT_FAILURE);
	}
	temp = *head;
	temp->next->n *= temp->n;
	*head = temp->next;
	(*head)->prev = NULL;
	free(temp);
}

