/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putint.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sstanfel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/25 16:51:12 by sstanfel          #+#    #+#             */
/*   Updated: 2022/11/25 21:46:49 by sstanfel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	count_int(int n)
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

static char	*ft_itoa(int n)
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

int	ft_putint(int i)
{
	int		c;
	char	*ptr;

	ptr = ft_itoa(i);
	c = ft_putstr(ptr);
	free(ptr);
	return (c);
}
