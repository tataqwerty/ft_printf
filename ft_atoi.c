/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkiselev <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/23 16:16:46 by tkiselev          #+#    #+#             */
/*   Updated: 2018/03/28 19:41:26 by tkiselev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int					ft_atoi(const char *str)
{
	int				i;
	int				sign;
	long long int	res;

	i = 0;
	sign = 1;
	res = 0;
	while ((str[i] == ' ' || str[i] == '\t' || str[i] == '\r' ||
	str[i] == '\f' || str[i] == '\v' || str[i] == '\n') && str[i] != '\0')
		i++;
	sign = (str[i] == '-') ? -1 : 1;
	if (str[i] == '-' || str[i] == '+')
		i++;
	while (str[i] >= '0' && str[i] <= '9' && res >= 0)
		res = res * 10 + (long long int)str[i++] - 48;
	if (res < 0)
	{
		if (sign == -1)
			return (0);
		return (-1);
	}
	return ((int)res * sign);
}
