/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkiselev <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/25 15:54:29 by tkiselev          #+#    #+#             */
/*   Updated: 2018/03/27 15:58:36 by tkiselev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	int		ft_count_words(char const *str, char c)
{
	char	*s;
	int		w;
	int		i;

	i = 0;
	w = 0;
	s = (char*)str;
	while (s[i] != '\0')
	{
		if (s[i] != c)
		{
			w++;
			while (s[i] != '\0' && s[i] != c)
				i++;
		}
		else
			i++;
	}
	return (w);
}

static	int		ft_word_len(char const *str, int i, char c)
{
	int		j;
	char	*s;

	j = i;
	s = (char*)str;
	while (s[j] != '\0' && s[j] != c)
		j++;
	return (j - i);
}

static	void	free_everything(char **array)
{
	int i;

	i = 0;
	while (array[i])
	{
		free(array[i]);
		i++;
	}
	free(array);
}

static	char	**help(char const *s, char c, int i, int j)
{
	char	**arr;
	int		k;

	arr = (char**)malloc(sizeof(char*) * (ft_count_words(s, c) + 1));
	if (arr == NULL)
		return (0);
	while (++i < ft_count_words(s, c))
	{
		while ((char)s[j] != '\0' && (char)s[j] == c)
			j++;
		if (!(arr[i] = ft_strnew(ft_word_len(s, j, c))))
		{
			free_everything(arr);
			return (0);
		}
		k = 0;
		while ((char)s[j] != '\0' && (char)s[j] != c)
		{
			arr[i][k] = (char)s[j];
			j++;
			k++;
		}
	}
	arr[i] = 0;
	return (arr);
}

char			**ft_strsplit(char const *s, char c)
{
	int		i;
	int		j;

	if (s == NULL)
		return (0);
	i = -1;
	j = 0;
	return (help(s, c, i, j));
}
