#include "monty.h"

/**
 * fpstr - prints the string starting at the top of the stack
 * @head: stack head
 * @line_number: line number
 * Return: no return
 */


void fpstr(stack_t **head, unsigned int line_number)
{
	stack_t *temp;

	(void) line_number;
	temp = *head;
	while (temp && temp->n > 0 && temp->n <= 127)
	{
		putchar(temp->n);
		temp = temp->next;
	}
	putchar('\n');
}
