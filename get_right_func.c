#include "monty.h"

char data[SIZE];
/**
 * get_right_func - return the right function.
 *
 * Return: nothing.
 */
void (*get_right_func())(stack_t**, unsigned int)
{
	instruction_t instruction[] = {
		{"push", push_item},
		{"pall", pall_stack},
		{"pint", pint_stack},
		{"pop", pop_stack},
		{"swap", swap_stack},
		{"add", add_stack},
		{"nop", nop_skip},
		{"sub", sub_stack},
		{"div", div_stack},
		{"mul", mul_stack},
		{"mod", mod_stack},
		{NULL, NULL}
	};
	int i = 0;
	char *token, data_copy[SIZE];

	strcpy(data_copy, data);
	token = strtok(data_copy, " \t\n");
	if (token == NULL || token[0] == '#')
		return (NULL);
	for (i = 0; instruction[i].opcode; i++)
		if (strcmp(instruction[i].opcode, token) == 0)
			return (instruction[i].f);

	return (no_match);
}

/**
 * nop_skip - skip the line.
 * @stack: linked list.
 * @line_number: the current line number.
 *
 * Return: nothing.
 */
void nop_skip(stack_t **stack, unsigned int line_number)
{
	(void) stack;
	(void) line_number;
}
