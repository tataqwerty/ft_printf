/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkiselev <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/26 17:31:50 by tkiselev          #+#    #+#             */
/*   Updated: 2018/03/28 18:52:23 by tkiselev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list		*ft_lstnew(void const *content, size_t content_size)
{
	t_list	*list;

	list = malloc(sizeof(t_list));
	if (!list)
		return (NULL);
	list->next = NULL;
	list->content = NULL;
	list->content_size = 0;
	if (content)
	{
		list->content = malloc(content_size);
		list->content = ft_memcpy(list->content, content, content_size);
		if (list->content == NULL)
		{
			free(list);
			list = NULL;
			return (NULL);
		}
		list->content_size = content_size;
	}
	return (list);
}
