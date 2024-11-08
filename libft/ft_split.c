/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sstanfel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/10 15:58:31 by sstanfel          #+#    #+#             */
/*   Updated: 2022/11/15 14:58:28 by sstanfel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	wordcount(char const *str, char c)
{
	int	counter;
	int	words;
	int	wordcounter;

	counter = 0;
	words = 0;
	wordcounter = 0;
	while (str[counter])
	{
		if (str[counter] != c && words == 0)
		{
			words = 1;
			wordcounter++;
		}
		else if (str[counter] == c)
			words = 0;
		counter++;
	}
	return (wordcounter);
}

static char	*malloced(char const *str, int start, int end)
{
	char	*newstr;
	int		counter;

	counter = 0;
	newstr = malloc(sizeof(char) * ((end - start) + 1));
	if (!newstr)
		return (0);
	while (start < end)
	{
		newstr[counter] = str[start];
		counter++;
		start++;
	}
	newstr[counter] = '\0';
	return (newstr);
}

char	**ft_split(char const *str, char set)
{
	size_t	i;
	size_t	j;
	int		index;
	char	**split;

	split = malloc(sizeof(char *) * (wordcount(str, set) + 1));
	if (!str || !split)
		return (0);
	i = 0;
	j = 0;
	index = -1;
	while (i <= ft_strlen(str))
	{
		if (str[i] != set && index < 0)
			index = i;
		else if ((str[i] == set || i == ft_strlen(str)) && index >= 0)
		{
			split[j++] = malloced(str, index, i);
			index = -1;
		}
		i++;
	}
	split[j] = 0;
	return (split);
}
