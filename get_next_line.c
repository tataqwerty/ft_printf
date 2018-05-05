/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkiselev <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/06 10:29:18 by tkiselev          #+#    #+#             */
/*   Updated: 2018/04/22 10:50:18 by tkiselev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	char		*ft_realloc(char *ptr, int size)
{
	int				i;
	char			*new_ptr;

	i = 0;
	if (!(new_ptr = ft_strnew(size)))
		return (0);
	if (ptr)
	{
		while (ptr[i] != '\0')
		{
			new_ptr[i] = ptr[i];
			i++;
		}
		free(ptr);
	}
	return (new_ptr);
}

static	int			ft_put_n(t_gnl *list, char **line, int *size)
{
	int				flag;
	int				n;

	n = 0;
	flag = 0;
	while (list->buffer[n] != '\0' && list->buffer[n] != '\n')
		n++;
	(*size) += n;
	*line = ft_realloc(*line, *size);
	ft_memccpy(*line + ft_strlen(*line), list->buffer, '\n', n);
	if (list->buffer[n] == '\n')
	{
		flag = 1;
		n++;
		ft_memmove(list->buffer, list->buffer + n,
			ft_strlen(list->buffer + n));
		ft_bzero(list->buffer + ft_strlen(list->buffer + n), n);
	}
	else
		ft_bzero(list->buffer, n);
	return (flag);
}

static	t_gnl		*ft_new_list(const int fd, t_gnl *head)
{
	t_gnl			*list;

	list = head;
	if (!head)
	{
		head = (t_gnl*)malloc(sizeof(t_gnl));
		head->buffer = ft_strnew(BUFF_SIZE);
		head->tmp_fd = fd;
		head->next = NULL;
		return (head);
	}
	while (list)
	{
		if (list->tmp_fd == fd)
			return (list);
		list = list->next;
	}
	while (head->next)
		head = head->next;
	head->next = (t_gnl*)malloc(sizeof(t_gnl));
	head->next->buffer = ft_strnew(BUFF_SIZE);
	head->next->tmp_fd = fd;
	head->next->next = NULL;
	return (head->next);
}

int					get_next_line(const int fd, char **line)
{
	int				bytes;
	int				size;
	static	t_gnl	*head = NULL;
	t_gnl			*list;

	size = 0;
	if (fd < 0 || !line)
		return (-1);
	*line = NULL;
	if (!head)
		head = ft_new_list(fd, head);
	list = ft_new_list(fd, head);
	if (list->buffer && list->buffer[0] != '\0')
		if ((ft_put_n(list, line, &size)) == 1)
			return (1);
	while ((bytes = read(fd, list->buffer, BUFF_SIZE)) > 0)
	{
		if (bytes != BUFF_SIZE)
			ft_bzero(list->buffer + bytes, BUFF_SIZE - bytes);
		if ((ft_put_n(list, line, &size)) == 1)
			return (1);
	}
	if (bytes == -1)
		return (-1);
	return (((*line) == NULL) ? 0 : 1);
}
