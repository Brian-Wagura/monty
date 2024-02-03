#include "monty.h"

/**
 * frotl - rotates the stack tothe top
 * @head: stack head
 * @line_number: line number
 * Return: no return
*/
void frotl(stack_t **head, __attribute__((unused)) unsigned int line_number)
{
	if (*head == NULL || (*head)->next == NULL)
	{
		return;
	}
	stack_t *last = *head;

	while (last->next != NULL)
	{
		last = last->next;
	}
	last->next = *head;
	(*head)->prev = last;
	*head = (*head)->next;
	(*head)->prev = NULL;
	last->next->next = NULL;
}
