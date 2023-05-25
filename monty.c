#include "monty.h"

char data[SIZE];
/**
 * main - the main program for the monty bytecode interpreter.
 * @argc: numbe rof argument passed to the interpreter.
 * @argv: list of argument passed to the interpreter.
 *
 * Return: 0 Success.
 */
int main(int argc, char *argv[])
{
	stack_t *stack = NULL;
	void (*func)(stack_t**, unsigned int);
	FILE *file;
	unsigned int line_number = 0;

	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
	file = fopen(argv[1], "r");
	if (file == NULL)
	{
		fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}
	while (fgets(data, sizeof(data), file) != NULL)
	{
		line_number++;
		func = get_right_func();
		if (func == NULL)
			continue;
		func(&stack, line_number);
	}
	fclose(file);
	free_stack(stack);
	return (0);
}

/**
 * free_stack - free the stack linked list.
 * @stack: linked list to be freed.
 *
 * Return: nothing.
 */
void free_stack(stack_t *stack)
{
	stack_t *tmp;

	while (stack != NULL)
	{
		tmp = stack;
		stack = stack->next;
		free(tmp);
	}
}
