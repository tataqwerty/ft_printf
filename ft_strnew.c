/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkiselev <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/25 12:09:01 by tkiselev          #+#    #+#             */
/*   Updated: 2018/03/25 12:14:20 by tkiselev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnew(size_t size)
{
	char	*data;

	data = (char *)malloc(sizeof(char) * (size + 1));
	if (data)
		ft_bzero(data, size + 1);
	return (data);
}
