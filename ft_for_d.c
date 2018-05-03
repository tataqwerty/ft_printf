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

char	*ft_ultoa_base(unsigned long int n, char *base)
{
	char				*str;
	unsigned long int	tmp_n;
	int					i;
	int					base_len;

	base_len = 0;
	while (base[base_len] != '\0')
		base_len++;
	tmp_n = n;
	i = 1;
	while ((tmp_n /= base_len))
		i++;
	if (!(str = (char*)malloc(sizeof(char) * (i + 1))))
		return (0);
	str[i] = '\0';
	while (--i >= 0)
	{
		str[i] = base[n % base_len];
		n /= base_len;
	}
	return (str);
}

int		ft_for_all_d(va_list list, t_struct *s)
{
	uintmax_t	unum;
	intmax_t	inum;

	if (s->type == 'd' || s->type == 'i' || s->type == 'D')
	{
		inum = ft_extract_intmax(list, s);
		return (ft_for_d(ft_ultoa_base((inum < 0) ?
		-inum : inum, "0123456789"), s, (inum < 0) ? 1 : 0));
	}
	unum = ft_extract_uintmax(list, s);
	if (s->type == 'u' || s->type == 'U')
		return (ft_for_d(ft_ultoa_base(unum, "0123456789"), s, 0));
	else if (s->type == 'o' || s->type == 'O')
		return (ft_for_d(ft_ultoa_base(unum, "01234567"), s, 0));
	else if (s->type == 'x' || s->type == 'p')
		return (ft_for_d(ft_ultoa_base(unum, "0123456789abcdef"), s, 0));
	else if (s->type == 'X')
		return (ft_for_d(ft_ultoa_base(unum, "0123456789ABCDEF"), s, 0));
	return (0);
}

int		ft_for_d(char *str, t_struct *s, int sign)
{
	char	*tmp2;
	char	*tmp;
	int		len;

	tmp = str;
	if (ft_precision(&str, s->precision) == -1)
		return (-1);
	tmp2 = str;
	len = ft_strlen(str);
	if (ft_width(&str, s) == -1)
		return (-1);
	if (s->type == 'x' || s->type == 'X' || s->type == 'o' || s->type == 'O')
	{
		if ((s->type == 'x' || s->type == 'X') && tmp[0] != '\0' && tmp[0] != '0')
			ft_prefix(&str, s, len, sign);
		else if ((s->type == 'o' || s->type == 'O') && tmp2[0] != '0')
			ft_prefix(&str, s, len, sign);
	}
	else
		ft_prefix(&str, s, len, sign);
	len = ft_strlen(str);
	write(1, str, len);
	free(str);
	return (len);
}

uintmax_t	ft_extract_uintmax(va_list list, t_struct *s)
{
	if (s->type != 'p' && s->type != 'U' && s->type != 'O')
	{
		if (s->size[0] == '\0')
			return (va_arg(list, unsigned int));
		else if (ft_strcmp(s->size, "hh") == 0)
			return ((unsigned char)va_arg(list, unsigned int));
		else if (ft_strcmp(s->size, "h") == 0)
			return ((unsigned short)va_arg(list, unsigned int));
	}
	return (va_arg(list, uintmax_t));
}

intmax_t	ft_extract_intmax(va_list list, t_struct *s)
{
	if ((s->size[0] != '\0' && ft_strcmp(s->size, "h") != 0
	&& ft_strcmp(s->size, "hh") != 0) || s->type == 'D')
		return (va_arg(list, intmax_t));
	else if (ft_strcmp(s->size, "hh") == 0)
		return ((char)va_arg(list, int));
	else if (ft_strcmp(s->size, "h") == 0)
		return ((short)va_arg(list, int));
	return (va_arg(list, int));
}