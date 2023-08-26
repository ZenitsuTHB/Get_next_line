/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_main.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avolcy <avolcy@student.42barcelon>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/14 12:28:40 by avolcy            #+#    #+#             */
/*   Updated: 2023/08/16 21:54:04 by avolcy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int		main(int argc, char **argv)
{
	int		fd;
	char	*line;
	int i = 0;
	fd = open(argv[1], O_RDONLY);
//	fd = open("test.txt",O_RDONLY);
	while (i < 5)
	{
		line = get_next_line(fd);
		if (line == NULL)
			break;
		printf("%s", line);
		i++;
		free (line);
	}
//	close(line);
	return (0);
}
