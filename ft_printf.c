/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkiselev <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/14 16:35:40 by tkiselev          #+#    #+#             */
/*   Updated: 2018/04/22 16:41:35 by tkiselev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

#include <stdio.h>
/*
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

int		ft_for_c(va_list list, t_struct *s)
{
	int i;

	i = 0;
	if (s->flag_zero && !s->flag_minus)
	{
		while (++i < s->width)
			write(1, "0", 1);
		ft_putchar(va_arg(list, int));
	}
	else if (s->flag_minus)
	{
		ft_putchar(va_arg(list, int));
		while (++i < s->width)
			write(1, " ", 1);
	}
	else
	{
		while (++i < s->width)
			write(1, " ", 1);
		ft_putchar(va_arg(list, int));
	}
	return (i);
}

int		ft_for_s(va_list list, t_struct *s)
{
	ft_putchar('A');
	return (0);
}

int		ft_magic(va_list list, t_struct *s)
{

	static int	(*func_arr[2])(va_list, t_struct *) = {ft_for_c, ft_for_s};

	func_arr[](list, s);
	static t_printf arr[2] = {{'c', ft_for_c}, {'s', ft_for_s}};

	i = 0;
	while (i < 2)
	{
		if (s->type == arr[i].type)
			return (arr[i].function(list, s));
		i++;
	}
	return (0);
}

int		ft_parse_spec(va_list list, char **format)
{
	t_struct *s;

	if (!format || !*format)
		return (0);
	s = create_struct();
	ft_spec_flags(format, s);
	ft_spec_width(format, s, list);
	ft_spec_precision(format, s, list);
	ft_spec_size(format, s);
	ft_spec_type(format, s);
	if (s->type != '\0')
		return (ft_magic(list, s));
	return (0);
}

int		ft_printf(const char *format, ...)
{
	va_list list;
	int		i;
	char	*s;

	i = 0;
	s = (char*)format;
	va_start(list, format);
	while (*s)
	{
		if (*s == '%')
		{
			s++;
			if (*s == '%')
			{
				ft_putchar(*s);
				i++;
				s++;
			}
			else
			{
				i += ft_parse_spec(list, &s);
			}
		}
		else
		{
			ft_putchar(*s);
			s++;
			i++;
		}
	}
	return (i);
}
*/

int		main(void)
{
	enum types type;

	type = "ll";
	printf("%d\n", type);
	//ft_putchar(21368);
	//printf("mine = %d\n", ft_printf("%c\n", 65));
	//printf("orig = %d\n", printf("%c\n", 65));
	//wint_t t = "ø";
	//printf("%lc", t);
	//printf("orig return value = %d\n", printf("%s\n", 123));
	//printf("mine return value = %d\n", ft_printf("%s\n", 123));
	return (0);
}
