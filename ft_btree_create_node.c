/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_btree_create_node.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkiselev <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/27 20:07:49 by tkiselev          #+#    #+#             */
/*   Updated: 2018/03/27 20:34:37 by tkiselev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_btree		*ft_btree_create_node(void *data)
{
	t_btree	*node;

	node = NULL;
	node = malloc(sizeof(t_btree));
	if (node)
	{
		node->left = NULL;
		node->right = NULL;
		node->data = data;
	}
	return (node);
}
