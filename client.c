/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgarzi-c <fgarzi-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/03 01:11:18 by fgarzi-c          #+#    #+#             */
/*   Updated: 2023/03/06 20:27:21 by fgarzi-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf/ft_printf.h"

void	ft_recive(int signo)
{
	if (signo == SIGUSR2)
		write(1, "Message successfully sended!\n", 29);
}

void	ft_sender(int pid, char *str)
{
	short int	offset;

	while (*str)
	{
		offset = -1;
		while (++offset < 8)
		{
			if ((1 << offset) & *str)
				kill(pid, SIGUSR2);
			else
				kill(pid, SIGUSR1);
			usleep(100);
		}
		str++;
	}
	while (--offset >= 0)
	{
		kill(pid, SIGUSR1);
		usleep(100);
	}
}

int	main(int ac, char **av)
{
	if (ac != 3)
	{
		write(1, "Error. Input type: <PID> <STRING>\n", 35);
		return (0);
	}
	signal(SIGUSR2, ft_recive);
	ft_sender(ft_atoi(av[1]), av[2]);
	return (0);
}
