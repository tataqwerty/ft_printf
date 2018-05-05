/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkiselev <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/20 16:21:25 by tkiselev          #+#    #+#             */
/*   Updated: 2018/03/28 19:03:28 by tkiselev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *b, int c, size_t len)
{
	unsigned char	*new_data;
	size_t			i;

	i = 0;
	new_data = (unsigned char*)b;
	while (i < len)
	{
		new_data[i] = (unsigned char)c;
		i++;
	}
	return ((void *)new_data);
}
