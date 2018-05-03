/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   new_printf.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkiselev <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/02 14:07:44 by tkiselev          #+#    #+#             */
/*   Updated: 2018/05/02 16:01:49 by tkiselev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"







t_struct	*ft_create_specificator(void)
{
	t_struct *s;

	if (!(s = (t_struct*)malloc(sizeof(t_struct))))
		return (NULL);
	s->width = 0;
	s->type = '\0';
	s->precision = -1;
	s->flag_zero = 0;
	s->flag_minus = 0;
	s->flag_plus = 0;
	s->flag_space = 0;
	s->flag_reshetka = 0;
	ft_bzero(s->size, 3);
	return (s);
}

void	ft_spec_main(va_list list, char **format_str, int *count, int &j)
{
	t_struct	*spec;

	(*format_str)++;
	if (!(spec = ft_create_specificator()))
	{
		*count = -1;
		return ;
	}
	ft_flags(format                             _str, spec);
	ft_width(format_str, spec);
	ft_precision(format_str, spec);
	ft_size(format_str, spec);
	ft_type(format_str, spec);
	if (spec->type != '\0')
		ft_magic();
}

void	ft_print_output(int *j)
{
	ft_putstr(line);
	ft_bzero(line, 100);
	*j = 0;
}

int		ft_printf(const char **format, ...)
{
	va_list list;
	char	*str;
	int		count;
	int		j;

	count = 0;
	j = -1;
	ft_bzero(line, 100);
	str = (char*)format;
	va_start(list, format);
	while (*str)
	{
		if (++j == 99 || *str == '%')
			ft_printf_output(&j);
		if (*str == '%')
		{
			ft_spec_main(list, &str, &count, &j);
			if (count == -1)
				return (-1);
		}
		else
			line[j] = (*str)++;
	}
	va_end(list);
	return (count);
}

int		main(void)
{
	ft_printf("", );
	return (0);
}
