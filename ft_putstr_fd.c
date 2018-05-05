/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkiselev <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/25 20:48:14 by tkiselev          #+#    #+#             */
/*   Updated: 2018/03/26 14:50:29 by tkiselev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putstr_fd(char const *s, int fd)
{
	char	*str;
	int		i;

	i = 0;
	if (s == NULL)
		return ;
	str = (char*)s;
	while (str[i] != '\0')
	{
		ft_putchar_fd(str[i], fd);
		i++;
	}
}
