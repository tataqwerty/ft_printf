/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkiselev <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/27 16:32:39 by tkiselev          #+#    #+#             */
/*   Updated: 2018/04/14 12:33:09 by tkiselev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	char	*create_base_arr(int base)
{
	char		*base_arr;
	int			i;

	i = 0;
	base_arr = (char*)malloc(sizeof(char) * (base + 1));
	while (i < base)
	{
		if (i >= 0 && i <= 9)
			base_arr[i] = i + 48;
		else if (i >= 10 && i <= 15)
			base_arr[i] = 55 + i;
		i++;
	}
	return (base_arr);
}

static	char	*help(char *base_arr, char *arr, int val, int base)
{
	int nb;
	int i;

	i = 1;
	nb = val;
	base_arr = create_base_arr(base);
	while ((nb /= base))
		i++;
	arr = (val < 0 && base == 10) ? ft_strnew(++i) : ft_strnew(i);
	if (val == 0)
	{
		arr[0] = '0';
		return (arr);
	}
	if (base == 10 && val < 0)
		arr[0] = '-';
	while (--i >= 0 && val)
	{
		arr[i] = (val > 0) ? base_arr[val % base] : base_arr[(val % base) * -1];
		val /= base;
	}
	return (arr);
}

char			*ft_itoa_base(int value, int base)
{
	char		*base_arr;
	char		*arr;

	base_arr = NULL;
	arr = NULL;
	if (base <= 1 || base >= 17)
		return (0);
	return (help(base_arr, arr, value, base));
}
