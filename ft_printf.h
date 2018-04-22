/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkiselev <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/18 13:14:36 by tkiselev          #+#    #+#             */
/*   Updated: 2018/04/22 16:52:01 by tkiselev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include "libft.h"
# include <stdarg.h>

typedef struct	s_struct
{
	int		width;
	char	type;
	char	size[3];
	int		precision;
	int		flag_zero;
	int		flag_reshetka;
	int		flag_minus;
	int		flag_plus;
	int		flag_space;
}				t_struct;

typedef struct
{
	char		type;
	int			(*function)(va_list list, t_struct *s);
}				t_printf;
#endif
