/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avolcy <avolcy@student.42barcelon>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/22 10:39:37 by avolcy            #+#    #+#             */
/*   Updated: 2023/08/22 23:07:17 by avolcy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

/*===================FT_STRLEN====================*/
size_t	ft_strlen(const char *string)
{
	size_t	i;
	
	if (!string)
		return (0);
	i = 0;
	while(string[i] != '\0')
		i++;
	return (i);
}
/*=================FT_STRCHR=======================*/

char	*ft_strchr(const char *string, int c)
{
	int	i;

	i = 0;
	while (string[i] != '\0')
	{
		if (string[i] == (char)c)
			return ((char *)&string[i]);
		i++;
	}
	if ((string[i]) == (char)c)
		return ((char *)&string[i]);
	return (NULL);
}

/*================FT_STRDUP=======================*/
char	*ft_strdup(const char *string)
{
	int		i;
	size_t	len;
	char	*duplicated;
	char	*tmp;

	len = ft_strlen(string);
	duplicated = (char *)malloc(sizeof(char) * len + 1);
	if (!duplicated)
	{
		free(duplicated);
		duplicated = NULL;
		return (NULL);
	}
	i = 0;
	while (string[i] != '\0')
	{
		duplicated[i] = string[i];
		i++;
	}
	duplicated[i] = '\0';
	tmp = duplicated;
	free(duplicated);
	duplicated = NULL;
	return (tmp);
}
/*=================FT_STRJOIN=====================*/

char	*ft_strjoin(char *storage, char *buffer)
{
	int		i;
	int		j;
	size_t	len;
	char	*new_storage;

	if (storage == NULL)
	{
		storage = malloc(sizeof(char) * 1);
		if(!storage)
			return NULL;
		storage[0] = '\0';
	}
	
	len = ft_strlen(storage);
	len = len + ft_strlen(buffer);
	new_storage = malloc(sizeof(char) * len + 1);
	if (!new_storage)
	{
//		free(buffer);//because buffer'll have data inside !!storage?
//		buffer = NULL;
		return (NULL);
	}
	i = 0;
	while (*storage && storage[i])
	{
		new_storage[i] = storage[i];
		i++;
	}
	j = 0;
	while (*buffer && buffer[j])
	{
		new_storage[i] = buffer[j++];
		i++;
	}
	new_storage[i] = '\0';
	free(storage);
	return (new_storage);
}
