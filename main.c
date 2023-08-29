# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include <limits.h>


#include "get_next_line.h"

int main(int ac, char **av)
{
//	char *line;
//	int fd1;
//	int fd2;
//	line = "pokemon";
//	fd1 = open(av[1], O_RDONLY);
//	fd2 = open(av[2], O_RDONLY);
//	while (line)
//	{
//		line = get_next_line(fd1);
//		if(line)
//		{
//			printf("%s",line);
//			free(line);
//		}
//	}
//
if (ac == 3)
	{
		int		fd1 = open(av[1], O_RDONLY);
		int		fd2 = open(av[2], O_RDONLY);
		char	*line1;
		char	*line2;
		line1 = "hola";
		while (line1)
		{
			line1 = get_next_line(fd1);
			line2 = get_next_line(fd2);

			printf("%s\n%s\n", line1, line2);
		free(line1);
		free(line2);
		}
	}



}
