#include "monty.h"

/**
 * fpchar - prints the char at the top of the stack
 * @head: stack head
 * @line_number: line number
 * Return: no return
*/
void fpchar(stack_t **head, unsigned int line_number)
{
	stack_t *temp;

	if (*head == NULL)
	{
		fprintf(stderr, "L%d: can't pchar, stack empty\n", line_number);
		fclose(globs.fm);
		free(globs.linecontent);
		free_stack(*head);
		exit(EXIT_FAILURE);
	}
	temp = *head;
	if (temp->n > 127 || temp->n < 0)
	{
		fprintf(stderr, "L%d: can't sub, stack too short\n", line_number);
		fclose(globs.fm);
		free(globs.linecontent);
		free_stack(*head);
		exit(EXIT_FAILURE);
	}
	putchar(temp->n);
	putchar('\n');
}
