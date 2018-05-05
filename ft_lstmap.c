/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkiselev <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/26 21:03:13 by tkiselev          #+#    #+#             */
/*   Updated: 2018/03/27 16:26:54 by tkiselev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	void	free_everything(t_list *list)
{
	while (list)
	{
		free(list->content);
		free(list);
		list = list->next;
	}
}

t_list			*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list	*current;
	t_list	*list_new;
	t_list	*temp;

	if (lst == NULL || *f == NULL)
		return (NULL);
	current = lst;
	list_new = f(current);
	temp = list_new;
	current = current->next;
	while (current)
	{
		temp->next = f(current);
		if (!temp->next)
		{
			free_everything(list_new);
			return (NULL);
		}
		temp = temp->next;
		current = current->next;
	}
	return (list_new);
}
