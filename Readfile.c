#include "monty.h"
#include <string.h>
/**
 * main - entry point
 * @argc: number of arguments
 * @argv: arguments
 * Return: 0(success)
 */
int main(int argc, char *argv[])
{
	int fd;
	stack_t *top = NULL;
	FILE *f;
	size_t n = 0;
	unsigned int line_num = 1;
	char *lineptr = NULL, **str1;

	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
	fd = open(argv[1], O_RDONLY);
	f = fdopen(fd, "r");
	if (fd == -1 || f == NULL)
	{
		if (fd != -1)
			close(fd);
		fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}
	while (getline(&lineptr, &n, f) != -1)
	{
		str1 = _strtok(lineptr);
		if (str1 == NULL || str1[0][0] == '#')
		{
			line_num++;
			continue;
		}
		search_function(&top, str1, lineptr, f, line_num);
		free_maloc(str1);

	}
	free_stack(top);
	free(lineptr);
	fclose(f);
	return (0);
}
/**
 * search_function - searches a function and calles it
 * @stack: top of the stack
 * @str1: tokinized strings
 * @line_number: number of the line
 * @lineptr: string from getline
 * @f: file stream
 * Return: nothing
 */
void search_function(stack_t **stack, char **str1,
		char *lineptr, FILE *f, unsigned int line_number)
{
	void (*fun)(stack_t **stack, unsigned int line_number);

	if (strcmp(str1[0], "push") == 0)
	{
		if (str1[1] != NULL && isnumber(str1[1]) == 0)
			operand = atoi(str1[1]);
		else
		{
			fprintf(stderr, "L%d: usage: push integer\n", line_number);
			free(lineptr);
			fclose(f);
			free_maloc(str1);
			free_stack(*stack);
			exit(EXIT_FAILURE);
		}
	}
	fun = get_fun(str1[0]);
	if (fun != NULL)
		fun(stack, line_number);
	else
	{
		fprintf(stderr, "L%d: unknown instruction %s\n", line_number, str1[0]);
		free(lineptr);
		fclose(f);
		free_maloc(str1);
		free_stack(*stack);
		exit(EXIT_FAILURE);
	}

}
/**
 * free_maloc - frees pointer to pointer
 * dynamic allocation
 * @array: double pointer
 * Return: nothing
 */
void free_maloc(char **array)
{
	int j = 0;

	while (array[j] != NULL)
	{
		j++;
	}
	while (j >= 0)
	{
		free(array[j]);
		j--;
	}
	free(array);
}
/**
 * free_stack - free every memory allocation by stack
 * @stack: top element of the stack
 *
 * Return: nothing
 */
void free_stack(stack_t *stack)
{
	stack_t *tmp;

	while (stack != NULL)
	{
		tmp = stack->next;
		free(stack);
		stack = tmp;
	}
}
