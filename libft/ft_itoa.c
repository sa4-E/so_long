/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sstanfel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/31 17:10:12 by sstanfel          #+#    #+#             */
/*   Updated: 2022/11/02 16:40:01 by sstanfel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	count_int(int n)
{
	int	count;

	if (n == 0)
		return (1);
	count = 0;
	if (n < 0)
		count++;
	while (n != 0)
	{
		n = n / 10;
		count++;
	}
	return (count);
}

char	*ft_itoa(int n)
{
	char	*s;
	int		count;
	int		i;

	count = count_int(n);
	i = n;
	s = malloc(count_int(n) + 1);
	if (!s)
		return (0);
	while (count > 0)
	{
		if (n < 0)
			s[count - 1] = n % 10 * -1 + '0';
		else
			s[count - 1] = n % 10 + '0';
		n = n / 10;
		count--;
	}
	if (i < 0)
		s[0] = '-';
	s[count_int(i)] = '\0';
	return (s);
}

// int	main(void)
// {
// 	int c = -94920;
// 	printf("%s", ft_itoa(c));
// }