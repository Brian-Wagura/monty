#include "monty.h"

/**
 * frotr - rotates the stack to the bottom
 * @head: stack head
 * @counter: line number
 * Return: no return
 */

void frotr(stack_t **head, __attribute__((unused)) unsigned int counter)
{
	stack_t *last;
	stack_t *secondLast;

	if (*head == NULL || (*head)->next == NULL)
	{
		return;
	}
	last = *head;
	secondLast = NULL;

	while (last->next != NULL)
	{
		secondLast = last;
		last = last->next;
	}

	last->next = *head;
	last->prev = NULL;
	(*head)->prev = last;
	secondLast->next = NULL;
	*head = last;
}
