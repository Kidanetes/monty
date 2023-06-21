#include "monty.h"
/**
 * nop - do nothing
 * @stack: address of top element
 * @line_number: number of a line in which
 * the opcode is found
 * Return: nothing
 */
void nop(__attribute__ ((unused)) stack_t **stack,
	__attribute__ ((unused)) unsigned int line_number)
{
}

/**
 * pchar - prints the char at the top of the stack,
 * followed by a new line.
 * @stack: top element of stack
 * @line_number: the line in which the instructions is
 * found
 * Return: Nothing
 */
void pchar(stack_t **stack, unsigned int line_number)
{
	if (*stack == NULL)
	{
		fprintf(stderr, "L%d: can't pchar, stack empty\n", line_number);
		exit(EXIT_FAILURE);
	}
	if ((**stack).n < 0 || (**stack).n > 127)
	{
		fprintf(stderr, "L%d: can't pchar, value out of range\n", line_number);
		exit(EXIT_FAILURE);
	}
	printf("%c\n", (**stack).n);
}

/**
 * pstr - prints the string starting at the top of the stack
 * followed by a new line.
 * @stack: top element of stack
 * @line_number: the line in which the instructions is
 * found
 * Return: Nothing
 */
void pstr(stack_t **stack, __attribute__ ((unused)) unsigned int line_number)
{
	stack_t *tmp;

	if (*stack == NULL)
	{
		printf("\n");
	}
	else
	{
		tmp = *stack;
		while (tmp != NULL)
		{
			if (tmp->n <= 0 || tmp->n > 127)
				break;
			printf("%c", tmp->n);
			tmp = tmp->next;
		}
		printf("\n");
	}
}
/**
 * rotl - rotates the stack to the top.
 * @stack: top element of stack
 * @line_number: the line in which the instructions is
 * found
 * Return: Nothing
 */
void rotl(stack_t **stack, unsigned int line_number)
{
	int num1;
	stack_t *tmp, *tmp2;

	if (*stack == NULL || (**stack).next == NULL)
	{
	}
	else
	{
		num1 = (**stack).n;
		pop(stack, line_number);
		tmp = *stack;
		while (tmp->next != NULL)
			tmp = tmp->next;
		tmp2 = malloc(sizeof(stack_t));
		if (tmp2 == NULL)
		{
			fprintf(stderr, "Error: malloc failed\n");
			exit(EXIT_FAILURE);
		}
		tmp2->n = num1;
		tmp2->next = tmp->next;
		tmp2->prev = tmp;
		tmp->next = tmp2;
	}
}
/**
 * rotr - rotates the stack to the bottom.
 * @stack: top element of stack
 * @line_number: the line in which the instructions is
 * found
 * Return: Nothing
 */
void rotr(stack_t **stack, unsigned int line_number)
{
	stack_t *tmp, *tmp2;

	if (*stack == NULL || (**stack).next == NULL)
	{
	}
	else
	{
		tmp = *stack;
		while (tmp->next != NULL)
			tmp = tmp->next;
		num = tmp->n;
		tmp2 = tmp->prev;
		tmp2->next = NULL;
		free(tmp);
		push(stack, line_number);
	}
}
