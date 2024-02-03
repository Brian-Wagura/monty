#include "monty.h"

/**
 * execute - executes the opcode
 * @content: line content
 * @stack: head ll
 * @counter: line counter
 * @file: pointer to monty file
 * Return: no return
 */

int execute(char *content, stack_t **stack, unsigned int counter, FILE *file)
{
	instruction_t opst[] = {
		{"push", fpush},
		{"pall", fpall},
		{"pint", fpint},
		{"pop", fpop},
		{"swap", fswap},
		{"add", fadd},
		{"sub", fsub},
		{"div", fdiv},
		{"mul", fmul},
		{"mod", mod_op},
		{"nop", fnop},
		{"pchar", fpchar},
		{"pstr", fpstr},
		{"rotl", frotl},
		{"rotr", frotr},
		{NULL, NULL}};

	char *op;
	unsigned int i;

	op = strtok(content, " \n\t");
	if (op && op[0] == '#')
		return (0);

	globs.arg = strtok(NULL, " \n\t");

	for (i = 0; opst[i].opcode != NULL; i++)
	{
		if (strcmp(op, opst[i].opcode) == 0)
		{
			opst[i].f(stack, counter);
			return (0);
		}
	}

	fprintf(stderr, "L%d: unknown instruction %s\n", counter, op);
	fclose(file);
	free(content);
	free_stack(*stack);
	exit(EXIT_FAILURE);
}
