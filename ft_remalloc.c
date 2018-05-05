/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_remalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkiselev <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/23 12:10:53 by tkiselev          #+#    #+#             */
/*   Updated: 2018/05/05 18:54:31 by tkiselev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_remalloc(char *ptr, int size)
{
	int		i;
	char	*new_ptr;

	i = 0;
	if (!(new_ptr = (char *)malloc(sizeof(char)
	* (size + 1))))
		return (NULL);
	ft_bzero(new_ptr, size + 1);
	if (ptr)
	{
		while (ptr[i] != '\0')
		{
			new_ptr[i] = ptr[i];
			i++;
		}
		free(ptr);
	}
	return (new_ptr);
}
