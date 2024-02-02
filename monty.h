#ifndef MONTY_H
#define MONTY_H

#include <stdio.h>
#include <stdlib.h>

/**
 * struct stack_s - doubly linked list representation of a stack/queue.
 * @n: integer
 * @prev: points to the previous element of the stack/queue.
 * @next: points to the next element of the stack/queue
 *
 * Description: doubly linked list node structure for stacks, queues,
 * LIFO, FIFO.
 */

typedef struct stack_s
{
    int n;
    struct stack_s *prev;
    struct stack_s *next;
} stack_t;

/**
 * struct instruction_s - opcode and its function
 * @opcode: the opcode
 * @f: function to handle the opcode
 *
 * Description: opcode and its function
 * for stack, queues, LIFO/ FIFO
 */
typedef struct instruction_s
{
    char *opcode;
    void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;

/**
 * struct global - contains all globals
 * @arg: value
 * @fm: file stream for monty file
 * @linecontent: line content
 * @lifi: flag change (stack/queue).
 */
typedef struct global
{
    char *arg;
    FILE *fm;
    char *linecontent;
    int lifi;

} globs_t;

extern globs_t globs;

void fpush(stack_t **top, unsigned int line_number);
void fpall(stack_t **top, unsigned int line_number);
void fpint(stack_t **stack, unsigned int line_number);
void fpop(stack_t **stack, unsigned int line_number);

void addnode(stack_t **head, int n);
void addqueue(stack_t **head, int n);

void free_stack(stack_t *stack);

#endif /* MONTY_H */
