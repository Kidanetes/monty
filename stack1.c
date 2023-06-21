#include "monty.h"
/**
 * push - add element to the stack
 * @stack: element at the top
 * @line_number: number of the line in which
 * the current instruction is found
 * Return: void
 */
void push(stack_t **stack, __attribute__ ((unused))unsigned int line_number)
{
	stack_t	*new;

	new = malloc(sizeof(stack_t));
	if (new == NULL)
	{
		fprintf(stderr, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}
	if (*stack == NULL)
	{
		new->n = num;
		new->prev = NULL;
		new->next = NULL;
		*stack = new;
	}
	else
	{
		new->n = num;
		new->next = *stack;
		new->prev = NULL;
		(**stack).prev = new;
		*stack = new;
	}
}
#include "monty.h"
/**
 * pall - prints elements of the stack
 * @stack: top element
 * @line_number: input parameter
 * Return: void
 */
void pall(stack_t **stack, __attribute__ ((unused))unsigned int line_number)
{
	stack_t *tmp;

	tmp = *stack;
	while (tmp != NULL)
	{
		printf("%d\n", tmp->n);
		tmp = tmp->next;
	}
}
/**
 * pint - prints the top element
 * @stack: address of top element
 * @line_number: number of a line in which
 * the opcode is found
 * Return: nothing
 */
void pint(stack_t **stack, __attribute__ ((unused))unsigned int line_number)
{
	stack_t *top = *stack;

	if (*stack == NULL)
	{
		fprintf(stderr, "L%d: can't pint, stack empty\n", line_number);
		exit(EXIT_FAILURE);
	}
	printf("%d\n", top->n);
}
/**
 * pop - removes the top element
 * @stack: address of top element
 * @line_number: number of a line in which
 * the opcode is found
 * Return: nothing
 */
void pop(stack_t **stack, unsigned int line_number)
{
	stack_t *tmp;

	if (*stack == NULL)
	{
		fprintf(stderr, "L%d: can't pop an empty stack\n", line_number);
		exit(EXIT_FAILURE);
	}
	tmp = (**stack).next;
	if (tmp != NULL)
		tmp->prev = NULL;
	free(*stack);
	*stack = tmp;
}
/**
 * swap - swap the top 2 elements
 * @stack: address of top element
 * @line_number: number of a line in which
 * the opcode is found
 * Return: nothing
 */
void swap(stack_t **stack, unsigned int line_number)
{
	stack_t *tmp, *tmp2, *tmp3;

	if (*stack == NULL || (**stack).next == NULL)
	{
		fprintf(stderr, "L%d: can't swap, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}
	tmp = *stack;
	tmp2 = (**stack).next;
	tmp3 = tmp2->next;

	tmp2->prev = (**stack).prev;
	tmp2->next = tmp;
	tmp->prev = tmp2;
	tmp->next = tmp3;
	*stack = tmp2;
}

