/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgarzi-c <fgarzi-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/06 13:04:58 by fgarzi-c          #+#    #+#             */
/*   Updated: 2023/03/06 17:59:04 by fgarzi-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdarg.h>
# include <signal.h>

int		ft_atoi(const char *str);
int		ft_printf(const char *str, ...);
int		ft_nbrtohex(unsigned long n, char c);
void	print_spc(const char *str, int *len, va_list *ap);
size_t	ft_strlen(const char *s);
int		ft_numlen(long num, int base);
int		ft_putnbr(long n);
void	ft_putstr(char *s, int *len);

#endif
