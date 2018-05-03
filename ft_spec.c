/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_spec.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkiselev <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/23 11:09:51 by tkiselev          #+#    #+#             */
/*   Updated: 2018/05/03 15:11:16 by tkiselev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_spec_flags(char **format, t_struct *s)
{
	while (**format)
	{
		if (**format == '0')
			s->flag_zero = 1;
		else if (**format == '#')
			s->flag_reshetka = 1;
		else if (**format == '-')
			s->flag_minus = 1;
		else if (**format == '+')
			s->flag_plus = 1;
		else if (**format == ' ')
			s->flag_space = 1;
		else
			break ;
		(*format)++;
	}
}

void	ft_spec_width(char **format, t_struct *s, va_list list)
{
	int tmp;

	if (**format == '*')
	{
		(*format)++;
		tmp = va_arg(list, int);
		if (tmp < 0)
		{
			s->flag_minus = 1;
			tmp *= -1;
		}
		s->width = tmp;
	}
	else
	{
		while (**format >= '0' && **format <= '9')
			s->width = s->width * 10 + *(*format)++ - 48;
	}
}

void	ft_spec_precision(char **format, t_struct *s, va_list list)
{
	int tmp;

	if (**format == '.')
	{
		(*format)++;
		if (**format == '*')
		{
			(*format)++;
			tmp = va_arg(list, int);
			if (tmp >= 0)
				s->precision = tmp;
		}
		else
		{
			s->precision = 0;
			while (**format >= '0' && **format <= '9')
				s->precision = s->precision * 10 + *(*format)++ - 48 ;
		}
	}
}

void	ft_spec_size(char **format, t_struct *s)
{
	if ((**format == 'h' && *(*format + 1) == 'h') || (**format == 'l' && *(*format + 1) == 'l'))
	{
		s->size[0] = *(*format)++;
		s->size[1] = *(*format)++;
	}
	else if (**format == 'h' || **format == 'l' || **format == 'z' || **format == 'j')
		s->size[0] = *(*format)++;
}

void	ft_spec(va_list list, char **format, t_struct *s)
{
	ft_spec_flags(format, s);
	ft_spec_width(format, s, list);
	ft_spec_precision(format, s, list);
	ft_spec_size(format, s);
}