/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgarzi-c <fgarzi-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/06 13:18:43 by fgarzi-c          #+#    #+#             */
/*   Updated: 2023/02/11 14:40:46 by fgarzi-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	handle_string(va_list *ap, int *len)
{
	char	*str;

	str = va_arg(*ap, char *);
	if (!str)
		str = "(null)";
	ft_putstr(str, len);
	return ;
}

void	print_spc(const char *str, int *len, va_list *ap)
{
	char	c;

	if (*str == 117)
		*len += ft_putnbr(va_arg(*ap, unsigned int));
	else if (*str == 100 || *str == 105)
		*len += ft_putnbr(va_arg(*ap, int));
	else if (*str == 115)
		handle_string(ap, len);
	else if (*str == 37)
		*len += write(1, "%%", 1);
	else if (*str == 99)
	{
		c = va_arg(*ap, int);
		*len += write(1, &c, 1);
	}
	else if (*str == 120 || *str == 88)
		*len += ft_nbrtohex(va_arg(*ap, unsigned int), *str);
	else if (*str == 112)
	{
		*len += write(1, "0x", 2);
		*len += ft_nbrtohex(va_arg(*ap, uintptr_t), 120);
	}
	return ;
}
