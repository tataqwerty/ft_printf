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

int		ft_for_c(int c, t_struct *s)
{
	int i;

	i = 0;
	if (s->flag_zero && !s->flag_minus)
	{
		while (++i < s->width)
			write(1, "0", 1);
		write(1, &c, 1);
	}
	else if (s->flag_minus)
	{	
		write(1, &c, 1);
		while (++i < s->width)
			write(1, " ", 1);
	}
	else
	{
		while (++i < s->width)
			write(1, " ", 1);
		write(1, &c, 1);
	}
	return (i);
}

int		ft_for_lc(wchar_t c, t_struct *s)
{
	int i;

	if (MB_CUR_MAX == 1 && c >= 0 && c <= 255)
		return (ft_for_c(c, s));
	else if (MB_CUR_MAX != 4 || c < 0 || (i = ft_bytes(c) - 1) == -1)
		return (-1);
	else if (s->flag_zero && !s->flag_minus)
	{
		while (++i < s->width)
			write(1, "0", 1);
		ft_putchar(c);
	}
	else if (s->flag_minus)
	{
		ft_putchar(c);
		while (++i < s->width)
			write(1, " ", 1);
	}
	else
	{
		while (++i < s->width)
			write(1, " ", 1);
		ft_putchar(c);
	}
	return (i);
}

int		ft_for_all_c(va_list list, t_struct *s)
{
	if ((ft_strcmp(s->size, "l") == 0 && s->type == 'c') ||
	s->type == 'C')
		return (ft_for_lc(va_arg(list, wchar_t), s));
	return (ft_for_c(va_arg(list, int), s));
}

int		ft_for_all_s(va_list list, t_struct *s)
{
	wchar_t	*str1;
	char	*str2;

	if ((s->type == 's' && ft_strcmp(s->size, "l") == 0) || s->type == 'S')
	{
		str1 = va_arg(list, wchar_t*);
		if (str1 == NULL)
			str1 = L"(null)";
		return (ft_for_ls(str1, s));
	}
	else if (s->type == 's' && s->size[0] == '\0')
	{
		str2 = va_arg(list, char*);
		if (str2 == NULL)
			str2 = "(null)";
		return (ft_for_s(str2, s));
	}
	return (-1);
}

t_struct	*create_struct(void)
{
	t_struct *s;

	if (!(s = (t_struct*)malloc(sizeof(t_struct))))
		return (NULL);
	s->width = 0;
	s->type = '\0';
	s->precision = -1;
	s->flag_zero = 0;
	s->flag_reshetka = 0;
	s->flag_minus = 0;
	s->flag_plus = 0;
	s->flag_space = 0;
	ft_bzero(s->size, 3);
	return (s);
}