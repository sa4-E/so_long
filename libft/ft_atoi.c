/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin@42.fr <sstanfel>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/19 19:06:06 by marvin@42.f       #+#    #+#             */
/*   Updated: 2022/10/26 01:52:53 by marvin@42.f      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *str)
{
	int	i;
	int	deficitor;
	int	result;

	i = 0;
	deficitor = 0;
	result = 0;
	while (((str[i] >= 9 && str[i] <= 13) || str[i] == ' '))
		i++;
	while (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-' && deficitor == 0)
			deficitor = -1;
		else if (str[i] == '+' && deficitor == 0)
			deficitor = 1;
		else
			return (0);
		i++;
	}
	if (!(deficitor == -1))
		deficitor = 1;
	while (str[i] && (str[i] >= '0' && str[i] <= '9'))
		result = result * 10 + str[i++] - '0';
	return (deficitor * result);
}
// int	main(void)
// {
// 	char s[] = "1234567";
// 	int a;

// 	a = ft_atoi(s);
// 	printf("%d", a);
// 	return (0);
// }