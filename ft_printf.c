/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkiselev <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/14 16:35:40 by tkiselev          #+#    #+#             */
/*   Updated: 2018/04/23 21:20:20 by tkiselev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

#include <wchar.h>

#include <stdio.h>

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

void	ft_spec(va_list list, char **format, t_struct *s)
{
	ft_spec_flags(format, s);
	ft_spec_width(format, s, list);
	ft_spec_precision(format, s, list);
	ft_spec_size(format, s);
	ft_spec_type(format, s);
}

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
	(s->type == 'C' && s->size[0] == '\0'))
		return (ft_for_lc(va_arg(list, wchar_t), s));
	return (ft_for_c(va_arg(list, int), s));
}












int		ft_count_bytes(wchar_t *s)
{
	int res;
	int i;

	i = 0;
	res = 0;
	while (s[i] != '\0')
	{
		res += ft_bytes((int)s[i]);
		i++;
	}
	return (res);
}

int		ft_for_ls(wchar_t *str, t_struct *s)
{
	int	i;
	int	byte;
	int bytes;

	i = 0;
	bytes = ft_count_bytes(str);
	if (s->precision < bytes && s->precision != -1)
		bytes = s->precision;
	if (s->width > bytes)
	{
		if (s->flag_minus)
		{
			while (bytes > 0)
			{
				byte = ft_bytes(str[i]);
				if (byte > bytes)
					break ;
				ft_putchar(str[i++]);
				bytes -= byte;
			}
			while (i++ < s->width)
				write(1, " ", 1);
		}
	}
	return (0);
}





int		ft_for_all_s(va_list list, t_struct *s)
{
	if ((ft_strcmp(s->size, "l") == 0 && s->type == 's') ||
	(s->type == 'S' && s->size[0] == '\0'))
		return (ft_for_ls(va_arg(list, wchar_t*), s));
//	return (ft_for_s(va_arg(list, char*), s));
}



int		ft_magic(va_list list, t_struct *s)
{
	int i;
	static t_printf arr[] = {
		{'c', ft_for_all_c},
		{'C', ft_for_all_c},
		{'s', ft_for_all_s}
		};

	i = 0;
	while (i < 3)
	{
		if (s->type == arr[i].type)
			return (arr[i].function(list, s));
		i++;
	}
	return (0);
}

int		ft_parse_spec(va_list list, char **format, int *i)
{
	t_struct	*s;
	int			tmp;

	tmp = 0;
	if (!format || !*format)
		return (0);
	if (!(s = create_struct()))
		return (-1);
	ft_spec(list, format, s);
	if (s->type != '\0')
	{
		if ((tmp = ft_magic(list, s)) == -1)
			return (-1);
	}
	*i += tmp;
	return (tmp);
}

int		ft_obrabotka(va_list list, char **format, int *i)
{
	(*format)++;
	if (**format == '%')
	{
		write(1, &(*format), 1);
		(*format)++;
		*i += *i + 1;
		return (0);
	}
	else
		return (ft_parse_spec(list, format, i));
}

int		ft_printf(const char *format, ...)
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
			if ((ft_obrabotka(list, &(s), &i) == -1))
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

#include <locale.h>

int		main(void)
{
	setlocale(LC_ALL, "");
	ft_printf("%-10ls", L"⑂⑃");

	//printf("%d\n", printf("%lc\n", -1));
	//printf("%d\n", printf("%S", L"Привкет"));
	//ft_putchar(127);
	return (0);
}
