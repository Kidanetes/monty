#include "monty.h"
/**
 * push_q - push into the queue
 * @stack: front of the queue
 * @line_number: number of the line
 * Return: nothing
 */
void push_q(stack_t **stack, __attribute__ ((unused))unsigned int line_number)
{
	stack_t	*new, *tmp = *stack;

	new = malloc(sizeof(stack_t));
	if (new == NULL)
	{
		fprintf(stderr, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}
	if (*stack == NULL)
	{
		new->n = operand;
		new->prev = NULL;
		new->next = NULL;
		*stack = new;
	}
	else
	{
		new->n = operand;
		while (tmp->next != NULL)
			tmp = tmp->next;
		tmp->next = new;
		new->prev = tmp;
		new->next = NULL;
	}
}
