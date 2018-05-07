/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkiselev <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/18 13:14:36 by tkiselev          #+#    #+#             */
/*   Updated: 2018/05/07 14:25:28 by tkiselev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include "libft.h"
# include <stdarg.h>
# include <wchar.h>
# include <stdint.h>

typedef struct	s_struct
{
	int			width;
	char		type;
	char		size[3];
	int			precision;
	int			flag_zero;
	int			flag_reshetka;
	int			flag_minus;
	int			flag_plus;
	int			flag_space;
}				t_struct;

typedef struct
{
	char		type;
	int			(*function)(va_list list, t_struct *s);
}				t_printf;

int				ft_printf(const char *format, ...);
void			ft_spec_flags(char **format, t_struct *s);
void			ft_spec_width(char **format, t_struct *s, va_list list);
void			ft_spec_precision(char **format, t_struct *s, va_list list);
void			ft_spec_size(char **format, t_struct *s);
void			ft_parse_spec(va_list list, char **format, int *i);
void			ft_spec(va_list list, char **format, t_struct *s);
int				ft_has_unicode(wchar_t *str, int bytes);
int				ft_count_bytes(wchar_t *str, int bytes);
void			ft_s_helper(wchar_t *str, int bytes);
int				ft_for_ls(wchar_t *str, t_struct *s);
int				ft_for_s(char *str, t_struct *s);
int				ft_for_all_d(va_list list, t_struct *s);
int				ft_for_all_s(va_list list, t_struct *s);
int				ft_for_all_c(va_list list, t_struct *s);
int				ft_for_c(int c, t_struct *s);
int				ft_for_lc(wchar_t c, t_struct *s);
char			*ft_ultoa_base(unsigned long int n, char *base);
int				ft_for_all_d(va_list list, t_struct *s);
int				ft_for_d(char *str, t_struct *s, int sign);
uintmax_t		ft_extract_uintmax(va_list list, t_struct *s);
intmax_t		ft_extract_intmax(va_list list, t_struct *s);
int				ft_precision(char **str, int precision);
int				ft_width(char **str, t_struct *s);
void			ft_prefix_help(char **str, t_struct *s, int initial_len,
				char *prefix);
void			ft_add_prefix(char **str, t_struct *s, int initial_len,
				char *prefix);
void			ft_prefix(char **str, t_struct *s, int len, int sign);
t_struct		*create_struct(void);
void			ft_help_width(t_struct *s, va_list list, char **format);
#endif
