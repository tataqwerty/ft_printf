/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkiselev <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/10 09:39:04 by tkiselev          #+#    #+#             */
/*   Updated: 2018/04/14 12:41:34 by tkiselev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include "libft.h"
# define BUFF_SIZE 1

typedef struct		s_gnl
{
	char			*buffer;
	int				tmp_fd;
	struct s_gnl	*next;
}					t_gnl;

int					get_next_line(const int fd, char **line);
#endif
