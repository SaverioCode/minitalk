/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgarzi-c <fgarzi-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/01 22:50:39 by fgarzi-c          #+#    #+#             */
/*   Updated: 2023/02/11 14:40:27 by fgarzi-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf(const char *str, ...)
{
	va_list		ap;
	int			len;

	if (!str)
		return (0);
	va_start(ap, str);
	len = 0;
	while (*str)
	{
		if (*str != 37 && ++len)
			write(1, str, 1);
		else
			print_spc(++str, &len, &ap);
		str++;
	}
	va_end(ap);
	return (len);
}
