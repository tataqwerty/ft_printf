/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnequ.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkiselev <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/25 13:16:45 by tkiselev          #+#    #+#             */
/*   Updated: 2018/03/28 17:07:53 by tkiselev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_strnequ(char const *s1, char const *s2, size_t n)
{
	size_t	i;
	char	*s_s1;
	char	*s_s2;

	i = 0;
	if (n == 0)
		return (1);
	if (s1 == NULL || s2 == NULL)
		return (0);
	s_s1 = (char *)s1;
	s_s2 = (char *)s2;
	while (s_s1[i] == s_s2[i] && s_s1[i] != '\0'
			&& s_s2[i] != '\0' && i < (n - 1))
		i++;
	if (s_s1[i] == s_s2[i])
		return (1);
	return (0);
}
