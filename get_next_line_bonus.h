/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kasingh <kasingh@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 09:36:15 by kasingh           #+#    #+#             */
/*   Updated: 2023/12/19 09:59:33 by kasingh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# include <fcntl.h>
# include <stddef.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 5
# endif

# if BUFFER_SIZE < 0
#  undef BUFFER_SIZE
#  define BUFFER_SIZE 0
# endif

# ifndef MAX_FD
#  define MAX_FD 999
# endif

typedef struct s_list
{
	int				fd;
	char			*storage;
	char			*buffer;
	struct s_list	*next;
}					t_list;

char				*get_next_line(int fd);
size_t				ft_strlen(const char *str);
char				*ft_strdup(const char *src);
char				*ft_strchr(const char *str, int c);

#endif