/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkiselev <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/25 19:36:55 by tkiselev          #+#    #+#             */
/*   Updated: 2018/04/27 17:24:07 by tkiselev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <limits.h>

void	ft_putnbr(long int n)
{
	if (n >= 0 && n <= 9)
		ft_putchar(n + 48);
	else if (n < 0)
	{
		ft_putchar('-');
		if (n == LONG_MIN)
		{
			ft_putchar('9');
			n = n % 1000000000000000000;
		}
		ft_putnbr(n * -1);
	}
	else
	{
		ft_putnbr(n / 10);
		ft_putnbr(n % 10);
	}
}
