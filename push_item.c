#include "monty.h"

char data[SIZE];
/**
 * is_num - check if given char is a number or not.
 * @token: the string to be checked.
 *
 * Return: 1 on success. 0 on failure.
 */
int is_num(char *token)
{
	int i = 0;

	if (token == NULL)
		return (0);

	while (token[i])
	{
		if (token[0] == '-')
			continue;
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
	char *token;
	int n;

	token = strtok(data, " \t\n");
	token = strtok(NULL, " \t\n");
	if (token == NULL || !is_num(token))
	{
		fprintf(stderr, "L%d: usage: push integer\n", line_number);
		free_stack(*stack);
		exit(EXIT_FAILURE);
	}
	n = atoi(token);
	new = malloc(sizeof(stack_t));
	if (new == NULL)
	{
		fprintf(stderr, "Error: malloc failed\n");
		free_stack(*stack);
		exit(EXIT_FAILURE);
	}
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
