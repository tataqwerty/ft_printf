/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkiselev <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/14 16:35:40 by tkiselev          #+#    #+#             */
/*   Updated: 2018/05/03 18:05:19 by tkiselev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_has_unicode(wchar_t *str, int bytes)
{
	int i;
	int byte;

	i = 0;
	while (bytes > 0)
	{
		byte = ft_bytes(str[i]);
		if (byte != 1)
			return (1);
		bytes -= byte;
		i++;
	}
	return (0);
}

int		ft_count_bytes(wchar_t *str, int bytes)
{
	int res;
	int byte;
	int i;

	i = -1;
	res = 0;
	if (bytes == -1)
	{
		while (str[++i] != '\0')
			res += ft_bytes(str[i]);
	}
	else
	{
		while (bytes > 0)
		{
			byte = ft_bytes(str[++i]);
			if (bytes < byte)
				break ;
			res += byte;
			bytes -= byte;
		}
	}
	return (res);
}

void	ft_s_helper(wchar_t *str, int bytes)
{
	int i;
	int byte;

	i = -1;
	while (bytes > 0)
	{
		byte = ft_bytes(str[++i]);
		ft_putchar(str[i]);
		bytes -= byte;
	}
}

int		ft_for_ls(wchar_t *str, t_struct *s)
{
	int tmp;
	int len;

	len = ft_count_bytes(str, -1);
	if (s->precision < len && s->precision != -1)
		len = s->precision;
	len = ft_count_bytes(str, len);
	if (ft_has_unicode(str, len) == 1 && MB_CUR_MAX != 4)
		return (-1);
	if (s->flag_minus)
	{
		ft_s_helper(str, len);
		while (len < s->width && ++len)
			write(1, " ", 1);
	}
	else
	{
		tmp = len;
		while (len < s->width && ++len)
			write(1, (s->flag_zero) ? "0" : " ", 1);
		ft_s_helper(str, tmp);
	}
	return (len);
}

int		ft_for_s(char *str, t_struct *s)
{
	int i;
	int j;
	int strlen;

	strlen = ft_strlen(str);
	i = -1;
	j = -1;
	if (s->precision < strlen && s->precision != -1)
		strlen = s->precision;
	if (s->flag_minus)
	{
		while (++i < strlen)
			write(1, &str[i], 1);
		while (i < s->width && ++i)
			write(1, " ", 1);
	}
	else
	{
		while (++i < (s->width - strlen))
			write(1, (s->flag_zero) ? "0" : " ", 1);
		while (++j < strlen && ++i)
			write(1, &str[j], 1);
	}
	return (i);
}
