/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkiselev <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/25 19:05:44 by tkiselev          #+#    #+#             */
/*   Updated: 2018/03/25 19:08:59 by tkiselev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putstr(char const *s)
{
	char	*str;
	int		i;

	i = 0;
	if (s == NULL)
		return ;
	str = (char*)s;
	while (str[i] != '\0')
	{
		ft_putchar(str[i]);
		i++;
	}
}
