#include "monty.h"

/**
 * swap_stack - swaps the top two elements of the stack.
 * @stack: lnked list.
 * @line_number: the current line number.
 *
 * Return: nothing.
 */
void swap_stack(stack_t **stack, unsigned int line_number)
{
	int len = 0, val;
	stack_t *tmp = *stack;

	while (tmp != NULL)
	{
		len++;
		tmp = tmp->next;
	}

	if (len < 2)
	{
		fprintf(stderr, "L%d: can't swap, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}
	tmp = *stack;
	val = tmp->n;
	tmp->n = tmp->next->n;
	tmp->next->n = val;
}
