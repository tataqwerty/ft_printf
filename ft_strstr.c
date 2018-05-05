/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkiselev <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/21 21:49:06 by tkiselev          #+#    #+#             */
/*   Updated: 2018/03/28 19:37:14 by tkiselev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strstr(const char *big, const char *little)
{
	char	*s_big;
	char	*s_little;
	int		i;
	int		j;

	i = 0;
	s_big = (char*)big;
	s_little = (char*)little;
	if (s_little[0] == '\0')
		return (s_big);
	while (s_big[i] != '\0')
	{
		j = 0;
		if (s_big[i] == s_little[j])
		{
			while (s_big[i + j] == s_little[j] && s_little[j] != '\0'
					&& s_big[i + j] != '\0')
				j++;
			if (s_little[j] == '\0')
				return (s_big + i);
		}
		i++;
	}
	return (0);
}
