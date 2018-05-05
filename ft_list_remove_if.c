/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_remove_if.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkiselev <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/14 11:12:02 by tkiselev          #+#    #+#             */
/*   Updated: 2018/04/14 12:34:50 by tkiselev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_list_remove_if(t_list **begin_list, void *data_ref, int (*cmp)())
{
	t_list	*list;

	if (!begin_list || !*begin_list)
		return ;
	list = *begin_list;
	while (list && (cmp(list->content, data_ref)) == 0)
	{
		free(list);
		list = list->next;
		*begin_list = list;
	}
	if (!list)
		return ;
	while (list->next)
	{
		if ((cmp(list->next->content, data_ref)) == 0)
		{
			free(list->next);
			list->next = list->next->next;
		}
		else
			list = list->next;
	}
}
