/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_btree_apply_postfix.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkiselev <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/27 20:39:20 by tkiselev          #+#    #+#             */
/*   Updated: 2018/03/27 20:41:21 by tkiselev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_btree_apply_postfix(t_btree *root, void (*f)(void *))
{
	if (root == NULL)
		return ;
	ft_btree_apply_postfix(root->left, f);
	ft_btree_apply_postfix(root->right, f);
	f(root->data);
}
