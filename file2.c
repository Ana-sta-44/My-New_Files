#include "main.h"


/**
 * my_read_input - The function that read inputs from non-interactive mode.
 *
 * Return: input read
 */
/*char *my_read_input(void)
{
	char *line = NULL;
	size_t line_len = 0;
	char ch;
	char *newline;

	while ((ch = getchar()) != '\0')
	{
		if (line_len == 0)
		{
			line = malloc(1);
		}
		else
		{
			line = realloc(line, line_len + 1);
		}

		line[line_len++] = ch;
	}

	*Remove newline character if present*/
        newline = strchr(line, '\n');
        if (newline)
	{
            *newline = '\0';
        }



/*	line[line_len] = '\0';*

	return (line);
	}*/



char *my_read_input(void)
{
	int buffer_size = 1024, index = 0;
	char *input = malloc(sizeof(char) * buffer_size);
	ssize_t bytesRead;
	char d;
	char *more_input = NULL;
/*	char *newline;*/

	if (!input)
	{
		perror("Memory allocation error");
		free(input);
		exit(EXIT_FAILURE);
	}
	while ((bytesRead = read(STDIN_FILENO, &d, 1)) > 0)
	{
		if (d == '\n')
			break;
		input[index++] = d;
		if (index >= (buffer_size - 1))
		{
			buffer_size += 1024;

			more_input = realloc(input, buffer_size);

			if (!more_input)
			{
				perror("Memory reallocation error");
				free(input);
				exit(EXIT_FAILURE);
			}
			input = more_input;
		}
	}
	_kill(bytesRead, input);

/*	newline = strchr(input, '\n');
	if (newline)
	{
            *newline = '\0';
	    }*/
	/* add a NULL terminating character */
	/* to indicate end of string */
	/*input[index] = '\0';*/

	return (input);
}




/**
 * _kill - check for EOF condition empty input condtions
 * @n: the number of bytes read
 * @s: the buffer being read
 */

void _kill(ssize_t n, char *s)
{
	if (n == -1)
	{
		perror("Error reading from stdin");
		free(s);
		exit(127);
	}
	if (n == 0)
	{
		free(s);
		exit(EXIT_SUCCESS);
	}
}
