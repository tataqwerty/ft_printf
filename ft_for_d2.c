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

int			ft_precision(char **str, int precision)
{
	char	*tmp_s;
	int		len;

	len = ft_strlen(*str);
	if (precision == 0 && (*str)[0] == '0' && len == 1)
	{
		free(*str);
		*str = ft_strnew(0);
	}
	if (precision > len)
	{
		if (!(tmp_s = ft_strnew(precision - len)))
			return (-1);
		len = precision - len;
		while (--len >= 0)
			tmp_s[len] = '0';
		if (!(*str = ft_strjoinfree(tmp_s, *str, 3)))
			return (-1);
	}
	return (0);
}

int			ft_width(char **str, t_struct *s)
{
	char	*tmp_s;
	int		len;

	len = ft_strlen(*str);
	if (s->width > len)
	{
		if (!(tmp_s = ft_strnew(s->width)))
			return (-1);
		if (s->flag_zero && !s->flag_minus && s->precision == -1)
			ft_memset(tmp_s, '0', s->width);
		else
			ft_memset(tmp_s, ' ', s->width);
		if (s->flag_minus)
			ft_strncpy(tmp_s, *str, len);
		else
			ft_strncpy(tmp_s + s->width - len, *str, len);
		free(*str);
		*str = tmp_s;
	}
	return (0);
}

void		ft_prefix_help(char **str, t_struct *s, int initial_len,
			char *prefix)
{
	int		i;
	int		strlen;
	int		prefix_len;

	i = 0;
	strlen = ft_strlen(*str);
	prefix_len = ft_strlen(prefix);
	if (s->flag_minus)
	{
		ft_memmove(*str + prefix_len, *str, initial_len);
		ft_strncpy(*str, prefix, prefix_len);
	}
	else if (s->flag_zero)
		ft_strncpy(*str, prefix, prefix_len);
	else
	{
		while ((*str)[i] && (*str)[i + prefix_len] &&
		(*str)[i + prefix_len] == ' ')
			i++;
		ft_strncpy(*str + i, prefix, prefix_len);
	}
}

void		ft_add_prefix(char **str, t_struct *s, int initial_len,
			char *prefix)
{
	char	*new_str;
	int		strlen;
	int		prefix_len;

	strlen = ft_strlen(*str);
	prefix_len = ft_strlen(prefix);
	if ((prefix_len + initial_len) > strlen)
	{
		new_str = ft_strnew(prefix_len + initial_len);
		ft_strncpy(new_str, prefix, prefix_len);
		if (s->flag_minus || initial_len == strlen)
			ft_strncpy(new_str + prefix_len, *str, initial_len);
		else
			ft_strncpy(new_str + prefix_len, prefix + 1, prefix_len);
		free(*str);
		*str = new_str;
	}
	else
		ft_prefix_help(str, s, initial_len, prefix);
}

void		ft_prefix(char **str, t_struct *s, int len, int sign)
{
	if (s->type == 'd' || s->type == 'i' || s->type == 'D')
	{
		if (sign)
			ft_add_prefix(str, s, len, "-");
		else if (s->flag_plus)
			ft_add_prefix(str, s, len, "+");
		else if (s->flag_space)
			ft_add_prefix(str, s, len, " ");
	}
	else if ((s->type == 'x' && s->flag_reshetka) || s->type == 'p')
		ft_add_prefix(str, s, len, "0x");
	else if (s->type == 'X' && s->flag_reshetka)
		ft_add_prefix(str, s, len, "0X");
	else if ((s->type == 'o' || s->type == 'O') && s->flag_reshetka)
		ft_add_prefix(str, s, len, "0");
}
