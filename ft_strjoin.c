/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkiselev <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/25 14:02:11 by tkiselev          #+#    #+#             */
/*   Updated: 2018/03/28 21:19:05 by tkiselev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	j;
	size_t	i;
	char	*s;

	if (s1 == NULL && s2 == NULL)
		return (0);
	if (s1 == NULL || s2 == NULL)
		return ((s1 == NULL) ? (char *)s2 : (char *)s1);
	s = ft_strnew(ft_strlen(s1) + ft_strlen(s2));
	if (s == NULL)
		return (0);
	i = 0;
	j = 0;
	while (s1[i] != '\0')
	{
		s[i] = (char)s1[i];
		i++;
	}
	while (s2[j] != '\0')
	{
		s[i] = (char)s2[j];
		j++;
		i++;
	}
	return (s);
}
