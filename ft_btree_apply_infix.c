/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_btree_apply_infix.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkiselev <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/27 20:35:50 by tkiselev          #+#    #+#             */
/*   Updated: 2018/03/27 20:38:27 by tkiselev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_btree_apply_infix(t_btree *root, void (*f)(void *))
{
	if (root == NULL)
		return ;
	ft_btree_apply_infix(root->left, f);
	f(root->data);
	ft_btree_apply_infix(root->right, f);
}
