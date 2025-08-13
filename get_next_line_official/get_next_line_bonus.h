/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: weiyang <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/27 12:01:49 by weiyang           #+#    #+#             */
/*   Updated: 2025/05/30 16:34:01 by weiyang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE   42
# endif

# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>

# define OPEN_MAX	1024

typedef struct s_fd_buffer
{
	int					fd;
	char				*stash;
	struct s_fd_buffer	*next;
}	t_fd_buffer;

char	*extract_line(char *str);
int		ft_strlen(char *str);
char	*ft_strjoin(char *s1, char *s2);
char	*ft_strdup(char *s);
int		end_line(char *str);
char	*get_next_line(int fd);

#endif
