/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgarzi-c <fgarzi-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/28 02:37:37 by fgarzi-c          #+#    #+#             */
/*   Updated: 2023/02/11 12:31:45 by fgarzi-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putnbr(long n)
{
	int		strlen;
	char	temp[12];

	if (n == 0)
		return (write(1, "0", 1));
	strlen = ft_numlen(n, 10);
	if (n < 0)
	{
		temp[0] = '-';
		n *= -1;
	}
	temp[strlen] = 0;
	while (n > 0)
	{
		temp[--strlen] = (n % 10) + 48;
		n = (n - (n % 10)) / 10;
	}
	return (write(1, temp, ft_strlen(temp)));
}
