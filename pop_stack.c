#include "monty.h"

/**
 * pop_stack - emoves the top element of the stack.
 * @stack: linked list.
 * @line_number: the current line number.
 *
 * Return: nothing.
 */
void pop_stack(stack_t **stack, unsigned int line_number)
{
	stack_t *tmp = *stack;

	check_no_args(*stack, line_number);
	if (*stack == NULL)
	{
		fprintf(stderr, "L%d: can't pop an empty stack\n", line_number);
		exit(EXIT_FAILURE);
	}
	else
	{
		*stack = (*stack)->next;
		(*stack)->prev = NULL;
		free(tmp);
	}
}
