#include "monty.h"

/**
 * fdiv - divides the top two elements of the stack
 * @head: stack top
 * @line_number: line number
 * Return: no return
*/
void fdiv(stack_t **head, unsigned int line_number)
{
	stack_t *h;
	int len = 0, aux;

	h = *head;
	while (h)
	{
		h = h->next;
		len++;
	}
	if (len < 2)
	{
		fprintf(stderr, "L%d: can't div, stack too short\n", line_number);
		fclose(globs.fm);
		free(globs.linecontent);
		free_stack(*head);
		exit(EXIT_FAILURE);
	}
	h = *head;
	if (h->n == 0)
	{
		fprintf(stderr, "L%d: can't div, stack too short\n", line_number);
		fclose(globs.fm);
		free(globs.linecontent);
		free_stack(*head);
		exit(EXIT_FAILURE);
	}
	aux = h->next->n / h->n;
	h->next->n = aux;
	*head = h->next;
	free(h);
}
