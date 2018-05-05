/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkiselev <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/22 15:53:43 by tkiselev          #+#    #+#             */
/*   Updated: 2018/03/28 19:38:25 by tkiselev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t n)
{
	char	*s_big;
	char	*s_little;
	size_t	i;
	size_t	j;

	i = 0;
	s_big = (char*)big;
	s_little = (char*)little;
	if (s_little[0] == '\0')
		return (s_big);
	while (s_big[i] != '\0' && i < n)
	{
		j = 0;
		if (s_big[i] == s_little[j])
		{
			while (s_big[i + j] == s_little[j] && s_big[i + j] != '\0'
					&& s_little[j] != '\0' && (i + j) < n)
				j++;
			if (s_little[j] == '\0')
				return (s_big + i);
		}
		i++;
	}
	return (NULL);
}
