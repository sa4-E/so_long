/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sstanfel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/24 20:15:37 by sstanfel          #+#    #+#             */
/*   Updated: 2022/12/07 18:27:33 by sstanfel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_search_datatype(va_list list, const char s)
{
	int	count;

	count = 0;
	if (s == 'c')
		count += ft_putchar(va_arg(list, int));
	else if (s == 's')
		count += ft_putstr(va_arg(list, char *));
	else if (s == 'p')
		count += ft_putptr(va_arg(list, unsigned long long));
	else if (s == 'd' || s == 'i')
		count += ft_putint(va_arg(list, int));
	else if (s == 'u')
		count += ft_putunsigned(va_arg(list, unsigned int));
	else if (s == 'x' || s == 'X')
		count += ft_put_hexa(va_arg(list, unsigned int), s);
	else if (s == '%')
		count += ft_putchar('%');
	return (count);
}

int	ft_printf(const char *s, ...)
{
	va_list	list;
	int		i;
	int		count;

	i = 0;
	count = 0;
	va_start(list, s);
	while (s[i])
	{
		if (s[i] == '%')
		{
			count += ft_search_datatype(list, s[i + 1]);
			i++;
		}
		else
			count += ft_putchar(s[i]);
		i++;
	}
	va_end(list);
	return (count);
}
