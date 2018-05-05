/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkiselev <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/21 21:24:44 by tkiselev          #+#    #+#             */
/*   Updated: 2018/03/28 19:22:05 by tkiselev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char	*str;
	char	val;
	int		i;

	i = 0;
	str = (char*)s;
	val = (char)c;
	while (*str != '\0')
	{
		str++;
		i++;
	}
	while (*str != val && i > 0)
	{
		str--;
		i--;
	}
	if (*str == val)
		return (str);
	return (NULL);
}
