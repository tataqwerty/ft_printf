/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkiselev <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/25 14:18:06 by tkiselev          #+#    #+#             */
/*   Updated: 2018/03/28 19:27:10 by tkiselev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s)
{
	char	*str;
	int		i;
	int		j;
	int		k;

	i = 0;
	j = 0;
	k = -1;
	if (s == NULL)
		return (NULL);
	while (s[i] != '\0' && (s[i] == ' ' || s[i] == '\n' || s[i] == '\t'))
		i++;
	while (s[j] != '\0')
		j++;
	j--;
	while (i < j && (s[j] == ' ' || s[j] == '\n' || s[j] == '\t'))
		j--;
	str = ft_strnew(j - i + 1);
	if (str == NULL)
		return (0);
	while (++k < (j - i + 1))
		str[k] = (char)s[i + k];
	return (str);
}
