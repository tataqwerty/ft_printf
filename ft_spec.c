/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_spec.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkiselev <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/23 11:09:51 by tkiselev          #+#    #+#             */
/*   Updated: 2018/04/23 12:51:50 by tkiselev         ###   ########.fr       */
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
	if (**format == '*')
	{
		(*format)++;
		s->width = va_arg(list, int);
	}
	else
	{
		while (**format >= '0' && **format <= '9')
			s->width = s->width * 10 + *(*format)++ - 48;
	}
}

void	ft_spec_precision(char **format, t_struct *s, va_list list)
{
	if (**format == '.')
	{
		(*format)++;
		if (**format == '*')
		{
			(*format)++;
			s->precision = va_arg(list, int);
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

void	ft_spec_type(char **format, t_struct *s)
{
	if (**format == 's' || **format == 'S' || **format == 'p' || **format == 'd'
	|| **format == 'D' || **format == 'i' || **format == 'o'|| **format == 'O' ||
	**format == 'u' || **format == 'U' || **format == 'x' || **format == 'X' ||
	**format == 'c' || **format == 'C')
		s->type = **format;
	if (s->type != '\0')
		(*format)++;
}
