#include "monty.h"
/**
 * _add - add the top 2 elements
 * @stack: address of top element
 * @line_number: number of a line in which
 * the opcode is found
 * Return: nothing
 */
void _add(stack_t **stack, unsigned int line_number)
{
	int res;

	if (*stack == NULL || (**stack).next == NULL)
	{
		fprintf(stderr, "L%d: can't add, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}
	res = (**stack).n;
	pop(stack, line_number);
	(**stack).n = (**stack).n + res;
}
/**
 * _sub - sub the top 2 elements
 * @stack: address of top element
 * @line_number: number of a line in which
 * the opcode is found
 * Return: nothing
 */
void _sub(stack_t **stack, unsigned int line_number)
{
	int res;

	if (*stack == NULL || (**stack).next == NULL)
	{
		fprintf(stderr, "L%d: can't sub, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}
	res = (**stack).n;
	pop(stack, line_number);
	(**stack).n = (**stack).n - res;
}
/**
 * _mul - mul the top 2 elements
 * @stack: address of top element
 * @line_number: number of a line in which
 * the opcode is found
 * Return: nothing
 */
void _mul(stack_t **stack, unsigned int line_number)
{
	int res;

	if (*stack == NULL || (**stack).next == NULL)
	{
		fprintf(stderr, "L%d: can't mul, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}
	res = (**stack).n;
	pop(stack, line_number);
	(**stack).n = (**stack).n * res;
}
/**
 * _div - div the top 2 elements
 * @stack: address of top element
 * @line_number: number of a line in which
 * the opcode is found
 * Return: nothing
 */
void _div(stack_t **stack, unsigned int line_number)
{
	int res;

	if (*stack == NULL || (**stack).next == NULL)
	{
		fprintf(stderr, "L%d: can't div, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}
	if ((**stack).n == 0)
	{
		fprintf(stderr, "L%d: division by zero\n", line_number);
		exit(EXIT_FAILURE);
	}
	res = (**stack).n;
	pop(stack, line_number);
	(**stack).n = (**stack).n / res;
}
/**
 * _mod - mod the top 2 elements
 * @stack: address of top element
 * @line_number: number of a line in which
 * the opcode is found
 * Return: nothing
 */
void _mod(stack_t **stack, unsigned int line_number)
{
	int res;

	if (*stack == NULL || (**stack).next == NULL)
	{
		fprintf(stderr, "L%d: can't mod, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}
	if ((**stack).n == 0)
	{
		fprintf(stderr, "L%d: division by zero\n", line_number);
		exit(EXIT_FAILURE);
	}
	res = (**stack).n;
	pop(stack, line_number);
	(**stack).n = (**stack).n % res;
}

