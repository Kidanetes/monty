#include "monty.h"
#include <string.h>

int main(int argc, char *argv[])
{
	int fd;
	stack_t **top = NULL;
	FILE *f;
	size_t n = 0;
	unsigned int line_num = 0;
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
                fprintf(stderr,"Error: Can't open file %s\n", argv[1]);
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
		search_function(top, str1, line_num);
		free_maloc(str1);

	}
	free(lineptr);
	fclose(f);
	return(0);
}
void search_function(stack_t **stack, char **str1, unsigned int line_number)
{
	void (*fun)(stack_t **stack, unsigned int line_number);

	if (strcmp(str1[0], "push") == 0)
	{
		if (str1[1] != NULL && isnumber(str1[1]) == 0)
			operand = atoi(str1[1]);
		else
		{
			fprintf(stderr,  "L%d: usage: push integer\n", line_number);
			exit(EXIT_FAILURE);
		}
	}
	fun = get_fun(str1[0]);
	if (fun != NULL)
		fun(stack, line_number);
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
