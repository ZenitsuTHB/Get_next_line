/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avolcy <avolcy@student.42barcelon>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/18 12:14:29 by avolcy            #+#    #+#             */
/*   Updated: 2023/08/22 23:09:43 by avolcy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

/*==================FT_UPDATE=======================*/
char	*ft_update(char	*storage)
{
	int		i;
	int		j;
	size_t	len;
	char	*new_storage;

	if (!storage)
		return (NULL);
	i = 0;
	while(storage[i] != '\n' && storage[i] != '\0')// && !ft_strchr(storage, '\n'))
		i++;
	if (storage[i] == '\0')
	{
		free(storage);
		return (NULL);
	}
	i++;
	len = ft_strlen(storage);
	new_storage = malloc(sizeof(char) * (len - i) + 1);
	if (!new_storage)
	{
		free(storage);
		return (NULL);
	}
	j = 0;
	while (storage[i] != '\0'){
		new_storage[j++] = storage[i++];
	}
	new_storage[j] = '\0';
	free(storage);
	return (new_storage);
}
/*=================FT_EXTRACT======================*/

char	*ft_extract(char *storage)
{
	int		i;
	char	*line;

	if (storage == NULL)
		return (NULL);
	if (!storage[0])
		return (NULL);
	i = 0;
	while(storage[i] != '\n' && storage[i] != '\0')//!ft_strchr(storage, '\n'))
		i++;
	line = malloc(sizeof(char) * (i + 2));
	if (!line)
	{
		free(storage);
		line = NULL;
		return (NULL);
	}
	i = 0;
	while (storage[i] != '\n' && storage[i] != '\0' ){
		line[i] = storage[i];
		i++;
	}
	if (storage[i] == '\n'){
		line[i] = storage[i];
		i++;
	}
	line[i] ='\0';
	return (line);
}
/*==================FT_READ========================*/

char	*ft_read(int fd, char *storage)
{
	int		bytes_read;
	char	*buffer;
	
// we read till BUFFER_SIZE and store the data read in 
// buffer according to the BUFFER_SIZE 
// then we append the data read and stored in buffer to storage;
//  storage = (char *) malloc(1);
//	if (!storage)
//		return (NULL);
	buffer = (char *)malloc(sizeof(char) * 	BUFFER_SIZE + 1);
	if (!buffer)
	{
		free(buffer);
		buffer = NULL;
		return (NULL);
	}
	buffer[0] = '\0';
	bytes_read = 1;
	while (bytes_read > 0 && !ft_strchr(buffer, '\n'))// && read(fd, buffer, BUFFER_SIZE) != 0)
	{
		bytes_read = read(fd, buffer, BUFFER_SIZE);
		if (bytes_read == -1)
		{
			free(buffer);
//			buffer = NULL;
			free(storage);
			return (NULL);
		}
		if (bytes_read > 0)
		{
			buffer[bytes_read] = '\0';
			storage = ft_strjoin(storage, buffer);
		}
	}
	free(buffer);
	return (storage);
}
/*==================GET_NEXT_LINE==================*/

char	*get_next_line(int fd)
{
	char		*line;
	static char *storage = NULL;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	storage = ft_read(fd, storage);
	if (storage == NULL)
		return (NULL);
	line = ft_extract(storage);
	if (!line)
	{
		free(storage);
		storage = NULL;
		return (NULL);
	}
	storage = ft_update(storage);
	return (line);
}
