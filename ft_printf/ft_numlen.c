/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_numlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgarzi-c <fgarzi-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/10 22:31:07 by fgarzi-c          #+#    #+#             */
/*   Updated: 2023/02/11 14:36:48 by fgarzi-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_numlen(long num, int base)
{
	int	counter;

	counter = 0;
	if (num < 0 && ++counter)
		num *= -1;
	while (num > 0 && ++ counter)
		num = num / base;
	return (counter);
}
