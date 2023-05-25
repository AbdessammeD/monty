#include "monty.h"

/**
 * add_stack - adds the top two elements of the stack.
 * @stack: lnked list.
 * @line_number: the current line number.
 *
 * Return: nothing.
 */
void add_stack(stack_t **stack, unsigned int line_number)
{
	int len = 0;
	stack_t *tmp1 = *stack, *tmp2 = *stack;

	while (tmp1 != NULL)
	{
		len++;
		tmp1 = tmp1->next;
	}

	if (len < 2)
	{
		fprintf(stderr, "L%d: can't add, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}
	tmp1 = *stack;
	tmp2->next->n += tmp2->n;
	tmp2->next->prev = NULL;
	*stack = tmp2->next;
	free(tmp1);
}
