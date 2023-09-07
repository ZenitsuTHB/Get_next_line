/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avolcy <avolcy@student.42barcelon>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/07 18:04:40 by avolcy            #+#    #+#             */
/*   Updated: 2023/09/07 18:06:16 by avolcy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 4
# endif

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include <limits.h>

char		*get_next_line(int fd);
char		*ft_strdup(const char *s1);
size_t		ft_strlen(const char *string);
void		*ft_clean_up(char **alloc_mem);
char		*ft_strchr(const char *s, int c);
char		*ft_strjoin(char *storage, char *buffer);
#endif
