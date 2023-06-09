#ifndef MONTY_H
#define MONTY_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <ctype.h>

#define SIZE 64

extern char data[SIZE];

/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
 *
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO
 */
typedef struct stack_s
{
	int n;
	struct stack_s *prev;
	struct stack_s *next;
} stack_t;

/**
 * struct instruction_s - opcode and its function
 * @opcode: the opcode
 * @f: function to handle the opcode
 *
 * Description: opcode and its function
 * for stack, queues, LIFO, FIFO
 */
typedef struct instruction_s
{
	char *opcode;
	void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;


void (*get_right_func())(stack_t**, unsigned int);
void push_item(stack_t**, unsigned int);
void pall_stack(stack_t**, unsigned int);
void no_match(stack_t**, unsigned int);
void pint_stack(stack_t**, unsigned int);
void pop_stack(stack_t**, unsigned int);
void swap_stack(stack_t**, unsigned int);
void free_stack(stack_t *);
void nop_skip(stack_t**, unsigned int);
void add_stack(stack_t**, unsigned int);
void sub_stack(stack_t**, unsigned int);
void mul_stack(stack_t**, unsigned int);
void div_stack(stack_t**, unsigned int);
void mod_stack(stack_t**, unsigned int);

#endif
