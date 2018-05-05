/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_btree_apply_infix_reverse.c                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkiselev <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/27 20:52:49 by tkiselev          #+#    #+#             */
/*   Updated: 2018/03/27 20:58:36 by tkiselev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_btree_apply_infix_reverse(t_btree *root, void (*f)(void *))
{
	if (root == NULL)
		return ;
	ft_btree_apply_infix_reverse(root->right, f);
	f(root->data);
	ft_btree_apply_infix_reverse(root->left, f);
}
