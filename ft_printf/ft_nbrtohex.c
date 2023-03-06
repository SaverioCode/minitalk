/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_nbrtohex.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgarzi-c <fgarzi-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/06 14:34:41 by fgarzi-c          #+#    #+#             */
/*   Updated: 2023/02/11 14:39:33 by fgarzi-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_ulonglen(unsigned long num, int base)
{
	int	counter;

	counter = 0;
	if (num < 0 && ++counter)
		num *= -1;
	while (num > 0 && ++ counter)
		num = num / base;
	return (counter);
}

int	ft_nbrtohex(unsigned long n, char c)
{
	int		strlen;
	char	temp[30];
	int		rest;

	if (n == 0)
		return (write(1, "0", 1));
	strlen = ft_ulonglen(n, 16);
	temp[strlen] = 0;
	while (n > 0)
	{
		rest = n % 16;
		n = n / 16;
		if (rest >= 0 && rest < 10)
			temp[--strlen] = rest + 48;
		else if (rest > 9 && rest < 16)
			temp[--strlen] = rest + ((int)c - 33);
	}
	return (write(1, temp, ft_strlen(temp)));
}
