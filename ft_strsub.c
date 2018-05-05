/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkiselev <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/25 13:21:16 by tkiselev          #+#    #+#             */
/*   Updated: 2018/03/25 14:01:22 by tkiselev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	size_t	i;
	size_t	j;
	char	*sub_str;

	if (s == NULL)
		return (0);
	sub_str = ft_strnew(len);
	if (sub_str == NULL)
		return (0);
	i = start;
	j = 0;
	while (s[i] != '\0' && j < len)
	{
		sub_str[j] = (char)s[i];
		i++;
		j++;
	}
	return (sub_str);
}
