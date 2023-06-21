#include "monty.h"
#include <string.h>

int main(int argc, char *argv[])
{
	int fd;
	FILE *f;
	size_t n = 0;
	int j;
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
		/*printf("%s", lineptr);*/
		str1 = _strtok(lineptr);
		if (str1 != NULL)
		{
			j = 0;
			while (str1[j] != NULL)
			{
				printf("%s ", str1[j]);
				j++;
			}
			printf("\n");
			free_maloc(str1);
		}

	}
	free(lineptr);
	fclose(f);
	return(0);
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
