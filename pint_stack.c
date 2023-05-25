#include "monty.h"

/**
 * pint_stack - prints the value at the top of the stack.
 * @stack: linked list.
 * @line_number: the current line number.
 *
 * Return: nothing.
 */
void pint_stack(stack_t **stack, unsigned int line_number)
{
	if (*stack == NULL)
	{
		fprintf(stderr, "L%d: can't pint, stack empty\n", line_number);
		exit(EXIT_FAILURE);
	}
	else
		printf("%d\n", (*stack)->n);
}
