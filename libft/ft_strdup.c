/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sstanfel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/26 17:40:57 by marvin@42.f       #+#    #+#             */
/*   Updated: 2022/11/02 19:34:54 by sstanfel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	char	*shithead;
	size_t	i;

	i = 0;
	shithead = malloc(ft_strlen(s1) + 1);
	if (!shithead)
		return (NULL);
	while (s1[i])
	{
		shithead[i] = s1[i];
		i++;
	}
	shithead[i] = '\0';
	return (shithead);
}

// int	main(void)
// {
// 	char s[] = "this is shithead";
// 	printf("%s", ft_strdup(s));
// }