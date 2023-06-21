#include "monty.h"
/**
 * get_fun - return a function pointer from opcode
 * @s: opcode
 *
 * Return: pointer to function or NULL
 */
void (*get_fun(char *s))(stack_t **stack, unsigned int line_number)
{
	instruction_t funs[] = {
		{"push", push_s},
		{"pall", pall},
		{"pint", pint},
		{"pop", pop},
		{"swap", swap},
		{"add", _add},
		{"nop", nop},
		{"sub", _sub},
		{"mul", _mul},
		{"div", _div},
		{"mod", _mod},
		{"pchar", pchar},
		{"pstr", pstr},
		{"rotl", rotl},
		{"rotr", rotr},
		{NULL, NULL}
	};
	int i;

	for (i = 0; funs[i].opcode != NULL; i++)
	{
		if (strcmp(funs[i].opcode, s) == 0)
			return (funs[i].f);
	}
	return (NULL);
}
/**
 * isnumber - check a string is number or not
 * @str: input string
 *
 * Return: 0(number), 1(not a number)
 */
int isnumber(char *str)
{
	int i = 0;

	if (str == NULL)
		return (1);
	if (str[0] == '-')
	{
		if (str[1] == '\0')
			return (1);
		i++;
	}
	while (str[i] != '\0')
	{
		if (!(str[i] >= '0' && str[i] <= '9'))
			return (1);
		i++;
	}
	return (0);
}
