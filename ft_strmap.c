/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkiselev <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/25 12:33:57 by tkiselev          #+#    #+#             */
/*   Updated: 2018/03/28 20:25:20 by tkiselev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmap(char const *s, char (*f)(char))
{
	char	*new_s;
	int		i;

	i = 0;
	if (s == NULL || f == NULL)
		return (0);
	new_s = ft_strnew(ft_strlen(s));
	if (new_s == NULL)
		return (0);
	while (s[i] != '\0')
	{
		new_s[i] = f(s[i]);
		i++;
	}
	return (new_s);
}
