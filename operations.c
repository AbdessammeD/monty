#include "monty.h"

/**
 * add_stack - adds of the top two elements of the stack.
 * @stack: linked list.
 * @line_number: the current line number.
 *
 * Return: nothing.
 */
void add_stack(stack_t **stack, unsigned int line_number)
{
	int len = 0;
	stack_t *tmp = *stack;

	check_no_args(*stack, line_number);
	while (tmp != NULL)
	{
		len++;
		tmp = tmp->next;
	}

	if (len < 2)
	{
		fprintf(stderr, "L%d: can't add, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}
	tmp = *stack;
	tmp->next->n += tmp->n;
	tmp->next->prev = NULL;
	*stack = tmp->next;
	free(tmp);
}
/**
 * sub_stack -  sub of the top two elements of the stack.
 * @stack: linked list.
 * @line_number: the current line number.
 *
 * Return: nothing.
 */
void sub_stack(stack_t **stack, unsigned int line_number)
{
	int len = 0;
	stack_t *tmp = *stack;

	check_no_args(*stack, line_number);
	while (tmp != NULL)
	{
		len++;
		tmp = tmp->next;
	}

	if (len < 2)
	{
		fprintf(stderr, "L%d: can't sub, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}
	tmp = *stack;
	tmp->n -= tmp->next->n;
	tmp->next->prev = NULL;
	*stack = tmp->next;
	free(tmp);
}

/**
 * mul_stack -  mul of the top two elements of the stack.
 * @stack: linked list.
 * @line_number: the current line number.
 *
 * Return: nothing.
 */
void mul_stack(stack_t **stack, unsigned int line_number)
{
	int len = 0;
	stack_t *tmp = *stack;

	check_no_args(*stack, line_number);
	while (tmp != NULL)
	{
		len++;
		tmp = tmp->next;
	}

	if (len < 2)
	{
		fprintf(stderr, "L%d: can't mul, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}
	tmp = *stack;
	tmp->next->n *= tmp->n;
	tmp->next->prev = NULL;
	*stack = tmp->next;
	free(tmp);
}

/**
 * div_stack -  div of the top two elements of the stack.
 * @stack: linked list.
 * @line_number: the current line number.
 *
 * Return: nothing.
 */
void div_stack(stack_t **stack, unsigned int line_number)
{
	int len = 0;
	stack_t *tmp = *stack;

	check_no_args(*stack, line_number);
	while (tmp != NULL)
	{
		len++;
		tmp = tmp->next;
	}

	if (len < 2)
	{
		fprintf(stderr, "L%d: can't div, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}
	if ((*stack)->n == 0)
	{
		fprintf(stderr, "L%d: division by zero\n", line_number);
		exit(EXIT_FAILURE);
	}
	tmp = *stack;
	tmp->n /= tmp->next->n;
	tmp->next->prev = NULL;
	*stack = tmp->next;
	free(tmp);
}

/**
 * mod_stack -  mod of the top two elements of the stack.
 * @stack: linked list.
 * @line_number: the current line number.
 *
 * Return: nothing.
 */
void mod_stack(stack_t **stack, unsigned int line_number)
{
	int len = 0;
	stack_t *tmp = *stack;

	check_no_args(*stack, line_number);
	while (tmp != NULL)
	{
		len++;
		tmp = tmp->next;
	}

	if (len < 2)
	{
		fprintf(stderr, "L%d: can't mod, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}
	if ((*stack)->n == 0)
	{
		fprintf(stderr, "L%d: division by zero\n", line_number);
		exit(EXIT_FAILURE);
	}
	tmp = *stack;
	tmp->next->n %= tmp->n;
	tmp->next->prev = NULL;
	*stack = tmp->next;
	free(tmp);
}
