#include "monty.h"

/**
 * no_match - raises if the file contains an invalid instruction.
 * @stack: linked list.
 * @line_number: the line number where the error happened.
 *
 * Return: nothing.
 */
void no_match(stack_t **stack, unsigned int line_number)
{
	(void) stack;

	fprintf(stderr, "L%d: unknown instruction <opcode>\n", line_number);
	exit(EXIT_FAILURE);
}
