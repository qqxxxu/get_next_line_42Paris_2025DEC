*This project has been created as part of the 42 curriculum by qixu.*

**Description**
This project creates a function that reads line by line from a file and the standard input. It will return each line that was read. If an error occurs, or at the end of a file(EOF), NULL will be returned.
As for method, I am using the string method, instead of the linked list one.

**Instructions**
How to compile the project: 
1) testing this function using the main.c file written below:

#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "get_next_line.h"

int main(int argc, char **argv)
{
	int	fd;
	char *line;
	int	i;

	if (argc == 1)
	{
		fd = 0;
		printf("Reading from stdin\n");
	}
	else
	{
		fd = open(argv[1], O_RDONLY);
		if (fd < 0)
		{
			perror("open");
			return (1);
		}
	}
	i = 1;
	while ((line = get_next_line(fd))!= NULL)
	{
		printf("[%d]%s", i++, line);
		free(line);
	}
	if (argc > 1)
		close(fd);
	return (0);
}
2) cc -Wall -Wextra -Werror -D BUFFER_SIZE=n <files>.c

**Resources**
1. Youtube tutorial: https://www.youtube.com/watch?v=xgDSXNOHTIA
2. Gitbook: https://42-cursus.gitbook.io/guide/1-rank-01/get_next_line
3. Tester: https://github.com/kodpe/gnl-station-tester?tab=readme-ov-file
4. GNL tutorial: https://github.com/jdecorte-be/42-Get-next-line?tab=readme-ov-file
5. online C playground(that allows pasting!): https://codapi.org/c/