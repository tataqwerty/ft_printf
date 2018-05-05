/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkiselev <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/21 14:49:55 by tkiselev          #+#    #+#             */
/*   Updated: 2018/03/28 19:10:02 by tkiselev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	val;
	unsigned char	*s_new;
	size_t			i;

	i = 0;
	val = (unsigned char)c;
	s_new = (unsigned char*)s;
	while (i < n)
	{
		if (*s_new == val)
			return (s_new);
		s_new++;
		i++;
	}
	return (0);
}
