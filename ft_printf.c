/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkiselev <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/14 16:35:40 by tkiselev          #+#    #+#             */
/*   Updated: 2018/05/07 14:52:50 by tkiselev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void				ft_spec(va_list list, char **format, t_struct *s)
{
	ft_spec_flags(format, s);
	ft_spec_width(format, s, list);
	ft_spec_precision(format, s, list);
	ft_spec_size(format, s);
}

int					ft_magic(va_list list, t_struct *s)
{
	int				i;
	static t_printf	arr[] = {{'c', ft_for_all_c}, {'C', ft_for_all_c},
		{'s', ft_for_all_s}, {'S', ft_for_all_s}, {'d', ft_for_all_d},
		{'D', ft_for_all_d}, {'i', ft_for_all_d}, {'u', ft_for_all_d},
		{'U', ft_for_all_d}, {'x', ft_for_all_d}, {'X', ft_for_all_d},
		{'o', ft_for_all_d}, {'O', ft_for_all_d}, {'p', ft_for_all_d}
		};

	i = -1;
	while (++i < 14)
	{
		if (s->type == arr[i].type)
			return (arr[i].function(list, s));
	}
	return (ft_for_c(s->type, s));
}

void				ft_parse_spec(va_list list, char **format, int *i)
{
	t_struct		*s;
	int				tmp;

	(*format)++;
	tmp = 0;
	if (!format || !*format)
		return ;
	if (!(s = create_struct()))
		return ;
	ft_spec(list, format, s);
	if (**format != '\0')
		s->type = *(*format)++;
	if (s->type != '\0')
	{
		if ((tmp = ft_magic(list, s)) == -1)
		{
			free(s);
			*i = -1;
			return ;
		}
		*i += tmp;
	}
	free(s);
}

int					ft_printf(const char *format, ...)
{
	va_list			list;
	int				i;
	char			*s;

	i = 0;
	s = (char*)format;
	va_start(list, format);
	while (*s)
	{
		if (*s == '%')
		{
			ft_parse_spec(list, &s, &i);
			if (i == -1)
				return (-1);
		}
		else
		{
			ft_putchar(*s);
			s++;
			i++;
		}
	}
	va_end(list);
	return (i);
}
