/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgarzi-c <fgarzi-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/03 01:11:18 by fgarzi-c          #+#    #+#             */
/*   Updated: 2023/03/04 21:08:48 by fgarzi-c         ###   ########.fr       */
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
			usleep(500);
		}
		str++;
	}
	while (--offset >= 0)
	{
		kill(pid, SIGUSR1);
		usleep(500);
	}
//	usleep(300);
}

int	main(int ac, char **av)
{
	struct sigaction	sa;

	if (ac != 3)
	{
		write(1, "Error. Input type: <PID> <STRING>\n", 35);
		return (0);
	}
	ft_sender(ft_atoi(av[1]), av[2]);
	sa.sa_flags = SA_SIGINFO;
	sa.sa_sigaction = (void *)ft_recive;
	sigaction(SIGUSR2, &sa, NULL);
	pause();
	return (0);
}

