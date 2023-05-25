#include "monty.h"

char data[SIZE];

/**
 * check_no_args - check if there is more than one token.
 * @line_number: the current line number.
 *
 * Return: nothing.
 */
void check_no_args(stack_t *stack, unsigned int line_number)
{
	char *token, data_copy[SIZE];

	strcpy(data_copy, data);

	token = strtok(data_copy, " \t\n");
	token = strtok(NULL, "\t\n");
	if (token)
	{
		fprintf(stderr, "L%d: unknown instruction <opcode>\n", line_number);
		free_stack(stack);
		exit(EXIT_FAILURE);
	}
}
