#include "monty.h"

/**
 * fsub - subtraction
 * @head: stack head
 * @line_number: line number
 * Return: void
 */

void fsub(stack_t **head, unsigned int line_number)
{
	stack_t *temp = *head;
	int difference, node_count = 0;

	while (temp != NULL)
	{
		node_count++;
		temp = temp->next;
	}
	if (node_count < 2)
	{
		fprintf(stderr, "L%d: can't sub, stack too short\n", line_number);
		fclose(globs.fm);
		free(globs.linecontent);
		free_stack(*head);
		exit(EXIT_FAILURE);
	}
	temp = *head;
	difference = temp->next->n - temp->n;
	temp->next->n = difference;
	*head = temp->next;
	free(temp);
}
