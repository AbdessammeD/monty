#include "monty.h"

/**
 * pall_stack - print all stack nodes.
 * @stack: linked list to be printed.
 * @line_number: the current line number.
 *
 * Return: nothing.
 */
void pall_stack(stack_t **stack, unsigned int line_number)
{
	stack_t *tmp = *stack;

	(void) line_number;

	check_no_args(*stack, line_number);
	if (*stack == NULL)
		return;

	while (tmp != NULL)
	{
		printf("%d\n", tmp->n);
		tmp = tmp->next;
	}
}
