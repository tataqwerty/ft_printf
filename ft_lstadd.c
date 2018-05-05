/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkiselev <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/26 20:48:14 by tkiselev          #+#    #+#             */
/*   Updated: 2018/03/28 21:03:29 by tkiselev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd(t_list **alst, t_list *new)
{
	t_list *new_list;

	if (alst == NULL)
		return ;
	new_list = new;
	if (new_list)
	{
		new_list->next = *alst;
		*alst = new_list;
	}
}
