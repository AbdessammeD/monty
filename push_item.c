#include "monty.h"

/**
 * is_num - check if given char is a number or not.
 * @token: the string to be checked.
 *
 * Return: 1 on success. 0 on failure.
 */
int is_num(char *token)
{
	int i = 0;

	while (token[i])
	{
		if (token[i] < 48 || token[i] > 57)
			return (0);
		i++;
	}
	return (1);
}
/**
 * push_item - push the item to the stack.
 * @stack: stack linked list.
 * @line_number: current line number.
 *
 * Return:
 */
void push_item(stack_t **stack, unsigned int line_number)
{
	stack_t *new;
	char *token1, *content;
	int n;

	content = strdup(data);
	token1 = strtok(content, " ");
	token1 = strtok(NULL, " ");
	if (!is_num(token1))
	{
		fprintf(stderr, "L%d: usage: push integer\n", line_number);
		exit(EXIT_FAILURE);
	}
	n = atoi(token1);

	new = malloc(sizeof(stack_t));
	new->prev = NULL;
	new->n = n;
	new->next = NULL;

	if (*stack == NULL)
		*stack = new;
	else
	{
		new->next = *stack;
		(*stack)->prev = new;
		*stack = new;
	}
}
