/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkiselev <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/25 12:49:21 by tkiselev          #+#    #+#             */
/*   Updated: 2018/03/28 20:25:57 by tkiselev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	unsigned int	i;
	char			*str;

	i = 0;
	if (s == NULL || f == NULL)
		return (0);
	str = ft_strnew(ft_strlen(s));
	if (str == NULL)
		return (0);
	while (s[i] != '\0')
	{
		str[i] = f(i, s[i]);
		i++;
	}
	return (str);
}
