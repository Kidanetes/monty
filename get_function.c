#include "monty.h"
void (*f(char *s))(stack_t **stack, unsigned int line_number)
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
