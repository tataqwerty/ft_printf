/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkiselev <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/21 19:49:07 by tkiselev          #+#    #+#             */
/*   Updated: 2018/03/28 19:18:30 by tkiselev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t		ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t i;
	size_t j;

	i = 0;
	j = 0;
	while (dst[i] != '\0' && i < dstsize)
		i++;
	if (dst[i] == '\0')
	{
		while (src[j] != '\0' && (i + j) < (dstsize - 1))
		{
			dst[i + j] = (char)src[j];
			j++;
		}
		dst[i + j] = '\0';
	}
	return (i + ft_strlen(src));
}
