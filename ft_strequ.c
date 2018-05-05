/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strequ.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkiselev <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/25 13:09:34 by tkiselev          #+#    #+#             */
/*   Updated: 2018/03/25 13:15:45 by tkiselev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_strequ(char const *s1, char const *s2)
{
	int		i;
	char	*s_s1;
	char	*s_s2;

	i = 0;
	s_s1 = (char *)s1;
	s_s2 = (char *)s2;
	if (s1 == NULL || s2 == NULL)
		return (0);
	while (s_s1[i] == s_s2[i] && s_s1[i] != '\0' && s_s2[i] != '\0')
		i++;
	if (s_s1[i] == '\0' && s_s2[i] == '\0')
		return (1);
	return (0);
}
