#include "monty.h"

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
		{NULL, NULL}
	};
	int i = 0;
	char *token, *content;

	content = malloc(strlen(data) + 1);
	strcpy(content, data);
	token = strtok(content, " ");
	free(content);
	if (strcmp(token, "nop") == 0)
		exit(EXIT_SUCCESS);
	for (i = 0; instruction[i].opcode; i++)
		if (strcmp(instruction[i].opcode, token) == 0)
			return (instruction[i].f);

	return (no_match);
}
