/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_btree_apply_prefix.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkiselev <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/27 20:26:53 by tkiselev          #+#    #+#             */
/*   Updated: 2018/03/27 20:34:17 by tkiselev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_btree_apply_prefix(t_btree *root, void (*f)(void *))
{
	if (root == NULL)
		return ;
	f(root->data);
	ft_btree_apply_prefix(root->left, f);
	ft_btree_apply_prefix(root->right, f);
}
