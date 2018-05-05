/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdelone.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkiselev <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/26 18:38:15 by tkiselev          #+#    #+#             */
/*   Updated: 2018/03/28 20:33:48 by tkiselev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdelone(t_list **alst, void (*del)(void *, size_t))
{
	t_list *list;
	t_list *begin_list;

	if (alst == NULL)
		return ;
	list = *alst;
	if (list)
	{
		begin_list = list->next;
		if (del)
			del(list->content, list->content_size);
		free(list);
		list = NULL;
		*alst = begin_list;
	}
}
