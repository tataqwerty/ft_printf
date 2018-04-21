/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkiselev <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/18 13:14:36 by tkiselev          #+#    #+#             */
/*   Updated: 2018/04/21 20:26:09 by tkiselev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include "libft.h"

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

union Data
{
	int		c;
	char	*s;
};
#endif
