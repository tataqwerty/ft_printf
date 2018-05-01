/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkiselev <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/14 16:35:40 by tkiselev          #+#    #+#             */
/*   Updated: 2018/05/01 17:16:07 by tkiselev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

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














int		ft_count_bytes(wchar_t *str)
{
	int res;
	int i;

	i = 0;
	res = 0;
	while (str[i])
		res += ft_bytes(str[i++]);
	return (res);
}

int		ft_for_write(wchar_t *str, int bytes)
{
	int i;
	int res;
	int byte;

	res = 0;
	i = 0;
	while (bytes > 0)
	{
		byte = ft_bytes(str[i]);
		if (bytes < byte)
			break ;
		ft_putchar(str[i++]);
		bytes -= byte;
		res += byte;
	}
	return (res);
}

int		ft_for_skip(wchar_t *str, int width, int bytes)
{
	int i;
	int byte;
	int res;

	res = 0;
	i = 0;
	while (bytes > 0)
	{
		byte = ft_bytes(str[i++]);
		if (bytes < byte)
			break ;
		bytes -= byte;
		res += byte;
	}
	i = res - 1;
	while (++i < width)
		write(1, " ", 1);
	return (i - res);
}

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

int		ft_for_ls(wchar_t *str, t_struct *s)
{
	int i;
	int bytes;
	int bytes2;

	i = 0;
	bytes2 = 0;
	bytes = ft_count_bytes(str);
	if (ft_has_unicode(str, bytes) == 1 && MB_CUR_MAX != 4)
		return (-1);
	if (bytes > s->precision && s->precision != -1)
		bytes = s->precision;
	if (s->flag_minus)
	{
		bytes2 = ft_for_write(str, bytes) - 1;
		while (++bytes2 < s->width)
			write(1, " ", 1);
	}
	else
	{
		bytes2 = ft_for_skip(str, s->width, bytes);
		bytes2 += ft_for_write(str, bytes);
	}
	return (bytes2);
}

int		ft_for_s(char *str, t_struct *s)
{
	int		j;
	int		i;
	int 	bytes;

	i = 0;
	bytes = ft_strlen(str);
	if (bytes > s->precision && s->precision != -1)
		bytes = s->precision;
	if (s->flag_minus)
	{
		while (i < bytes)
			write(1, &str[i++], 1);
		while (bytes++ < s->width)
			write(1, " ", 1);
	}
	else
	{
		j = bytes;
		while (bytes++ < s->width)
			write(1, " ", 1);
		while (i < j)
			write(1, &str[i++], 1);
	}
	return (bytes - 1);
}

int		ft_for_all_s(va_list list, t_struct *s)
{
	wchar_t	*str1;
	char	*str2;

	if ((s->type == 's' && ft_strcmp(s->size, "l") == 0) ||
	(s->type == 'S' && s->size[0] == '\0'))
	{
		str1 = va_arg(list, wchar_t*);
		if (str1 == NULL)
		{
			ft_putstr("(null)");
			return (6);
		}
		return (ft_for_ls(str1, s));
	}
	else if (s->type == 's' && s->size[0] == '\0')
	{
		str2 = va_arg(list, char*);
		if (str2 == NULL)
		{
			ft_putstr("(null)");
			return (6);
		}
		return (ft_for_s(str2, s));
	}
	return (-1);
}





















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

int		ft_add_precision(char **str, int precision)
{
	char	*new_str;
	int		len;

	len = ft_strlen(*str);
	if (len == 1 && (*str)[0] == '0' && precision == 0)
	{
		free(*str);
		if (!(*str = (char*)malloc(sizeof(char))))
			return (1);
		(*str)[0] = '\0';
	}
	if (precision > len)
	{
		if (!(new_str = (char*)malloc(sizeof(char) * (precision + 1))))
			return (1);
		ft_memset(new_str, '0', precision);
		new_str[precision] = '\0';
		while (len > 0)
			new_str[--precision] = (*str)[--len];
		free(*str);
		*str = new_str;
	}
	return (0);
}

int		ft_add_width_zero_minus(char **str, t_struct *s)
{
	char *new_str;
	int len;
	int width;

	width = s->width;
	len = ft_strlen(*str);
	if (len < width)
	{
		if (!(new_str = (char*)malloc(sizeof(char) * (width + 1))))
			return (1);
		new_str[width] = '\0';
		if (s->flag_zero == 1 && s->flag_minus == 0 && s->precision == -1)
			ft_memset(new_str, '0', width);
		else
			ft_memset(new_str, ' ', width);
		if (s->flag_minus)
			ft_strncpy(new_str, *str, len);
		else
			ft_strncpy(new_str + (width - len), *str, len);
		free(*str);
		*str = new_str;
	}
	return (0);
}




void	ft_help_smt1(char **str, t_struct *s, int len, char *smt)
{
	int i;
	int	strlen;
	int smtlen;

	i = -1;
	strlen = ft_strlen(*str);
	smtlen = ft_strlen(smt);
	if (s->flag_minus)
	{
		*str = ft_remalloc(*str, len + smtlen);
		ft_memmove(*str + smtlen, *str, len);
		while (smt[++i] != '\0')
			(*str)[i] = smt[i];
		return ;
	}
	*str = ft_remalloc(*str, len + smtlen);
	ft_memmove(*str + smtlen, *str + 1, len);
	while (smt[++i] != '\0')
		(*str)[i] = smt[i];
}

void	ft_help_smt3(char **str, t_struct *s, int len, char *smt)
{
	int j;
	int i;
	int	strlen;
	int smtlen;

	i = 0;
	j = -1;
	strlen = ft_strlen(*str);
	smtlen = ft_strlen(smt);
	while ((*str)[i] == ' ')
		i++;
	i -= smtlen;
	while (smt[++j] != '\0')
		(*str)[i++] = smt[j];
}

void	ft_help_smt2(char **str, t_struct *s, int len, char *smt)
{
	int i;
	int	strlen;
	int smtlen;

	i = -1;
	strlen = ft_strlen(*str);
	smtlen = ft_strlen(smt);
	if (s->flag_minus)
	{
		ft_memmove(*str + smtlen, *str, len);
		while (smt[++i] != '\0')
			(*str)[i] = smt[i];
		return ;
	}
	if (s->flag_zero)
		while (smt[++i] != '\0')
			(*str)[i] = smt[i];
	else
		ft_help_smt3(str, s, len, smt);
}

void	ft_add_smt(char **str, t_struct *s, int len, char *smt)
{
	int i;
	int	strlen;
	int smtlen;

	i = -1;
	strlen = ft_strlen(*str);
	smtlen = ft_strlen(smt);
	if (len == strlen)
	{
		*str = ft_remalloc(*str, len + smtlen);
		ft_memmove(*str + smtlen, *str, len);
		while (smt[++i] != '\0')
			(*str)[i] = smt[i];
	}
	else if (smtlen + len > strlen)
		ft_help_smt1(str, s, len, smt);
	else
		ft_help_smt2(str, s, len, smt);
}

int		ft_add_prefix(char **str, t_struct *s, t_for_prefix *prefix_s)
{
	if ((s->type == 'o' || s->type == 'O') && prefix_s->initial_len < prefix_s->len)
		return (0);
	if (s->type == 'd' || s->type == 'i' || s->type == 'D')
	{
		if (prefix_s->sign)
			ft_add_smt(str, s, prefix_s->len, "-");
		else if (s->flag_plus)
			ft_add_smt(str, s, prefix_s->len, "+");
		else
			ft_add_smt(str, s, prefix_s->len, " ");
	}
	else if ((s->type == 'o' || s->type == 'O') && s->flag_reshetka)
		ft_add_smt(str, s, prefix_s->len, "0");
	else if (s->type == 'x' && s->flag_reshetka)
		ft_add_smt(str, s, prefix_s->len, "0x");
	else if (s->type == 'X' && s->flag_reshetka)
		ft_add_smt(str, s, prefix_s->len, "0X");
	else if (s->type == 'p')
		ft_add_smt(str, s, prefix_s->len, "0x7ffe");
	return (0);
}

t_for_prefix	*ft_struct_for_prefix(int sign, int len, int new_len)
{
	t_for_prefix *s;

	if (!(s = (t_for_prefix*)malloc(sizeof(t_for_prefix))))
		return (NULL);
	s->sign = sign;
	s->initial_len = len;
	s->len = new_len;
	return (s);
}

int		ft_for_d(char *str, t_struct *s, int sign)
{
	t_for_prefix *prefix_s;
	int len;

	len = ft_strlen(str);
	if (ft_add_precision(&str, s->precision))
		return (-1);
	prefix_s = ft_struct_for_prefix(sign, len, ft_strlen(str));
	if (ft_add_width_zero_minus(&str, s))
		return (-1);
	if (ft_add_prefix(&str, s, prefix_s))
		return (-1);
	len = ft_strlen(str);
	ft_putstr(str);
	free(str);
	return (len);
}

int		ft_for_all_d(va_list list, t_struct *s)
{
	intmax_t	inum;
	uintmax_t	unum;

	if (s->type == 'd' || s->type == 'i' || s->type == 'D')
	{
		if ((s->size[0] != '\0' && ft_strcmp(s->size, "h") != 0 && ft_strcmp(s->size, "hh") != 0) || s->type == 'D')
			inum = va_arg(list, intmax_t);
		else
			inum = va_arg(list, int);
		return (ft_for_d(ft_ultoa_base(inum > 0 ? inum : -inum, "0123456789"), s, inum < 0 ? 1 : 0));
	}
	else if (s->type == 'x' || s->type == 'X' || s->type == 'o' || s->type == 'O'
	|| s->type == 'u' || s->type == 'U')
	{
		if (s->size[0] != '\0' && ft_strcmp(s->size, "h") != 0 && ft_strcmp(s->size, "hh") != 0)
			unum = va_arg(list, unsigned long int);
		else
			unum = va_arg(list, unsigned int);
		if (s->type == 'u' || s->type == 'u')
			return (ft_for_d(ft_ultoa_base(unum, "0123456789"), s, 0));
		if (s->type == 'o' || s->type == 'O')
			return (ft_for_d(ft_ultoa_base(unum, "01234567"), s, 0));
		else if (s->type == 'X')
			return (ft_for_d(ft_ultoa_base(unum, "0123456789ABCDEF"), s, 0));
		return (ft_for_d(ft_ultoa_base(unum, "0123456789abcdef"), s, 0));
	}
	else if (s->type == 'p')
		return (ft_for_d(ft_ultoa_base(va_arg(list, unsigned int), "0123456789abcdef"), s, 0));
	return (0);
}

int		ft_magic(va_list list, t_struct *s)
{
	int i;
	static t_printf arr[] = {
		{'c', ft_for_all_c},
		{'C', ft_for_all_c},
		{'s', ft_for_all_s},
		{'S', ft_for_all_s},
		{'d', ft_for_all_d},
		{'D', ft_for_all_d},
		{'i', ft_for_all_d},
		{'u', ft_for_all_d},
		{'U', ft_for_all_d},
		{'x', ft_for_all_d},
		{'X', ft_for_all_d},
		{'o', ft_for_all_d},
		{'O', ft_for_all_d},
		{'p', ft_for_all_d}
		};

	i = 0;
	while (i < 14)
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
