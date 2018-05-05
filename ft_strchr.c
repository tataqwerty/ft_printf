/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkiselev <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/21 20:53:26 by tkiselev          #+#    #+#             */
/*   Updated: 2018/03/26 14:56:59 by tkiselev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	char val;
	char *str;

	val = (char)c;
	str = (char*)s;
	while (*str != '\0' && *str != val)
		str++;
	if (*str == val)
		return (str);
	return (NULL);
}
