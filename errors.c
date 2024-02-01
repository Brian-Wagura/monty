#include "monty.h"

/**
 * malloc_error - Main entry.
 * Return: void
 *
 * Description: print message if can't malloc.
 */
void malloc_error(void)
{
	fprintf(stderr, "Error: malloc failed\n");
	exit(EXIT_FAILURE);
}
