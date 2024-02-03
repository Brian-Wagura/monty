#include "monty.h"

/**
 * fmod- computes the rest of the division of the second
 * top element of the stack by the top element of the stack
 * @head: stack head
 * @line_number: line number
 * Return: no return
*/
void fmod(stack_t **head, unsigned int line_number)
{
	stack_t *temp;

	if (*head == NULL || (*head)->next == NULL)
	{
		fprintf(stderr, "L%d: can't mod, stack too short\n", line_number);
		fclose(globs.fm);
		free(globs.linecontent);
		free_stack(*head);
		exit(EXIT_FAILURE);
	}
	temp = *head;
	if (temp->n == 0)
	{
		fprintf(stderr, "L%d: can't mod, stack too short\n", line_number);
		fclose(globs.fm);
		free(globs.linecontent);
		free_stack(*head);
		exit(EXIT_FAILURE);
	}
	temp->next->n %= temp->n;
	*head = temp->next;
	(*head)->prev = NULL;
	free(temp);
}
