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

#include "lib_minitalk.h"

void	ft_recive(int signo)
{
	write(1, "Message successfully sended!\n", 29);
	signo = 0;  ///////
}

void	ft_sender(int pid, char *str)
{
	short int	offset;

	while (*str)
	{
		offset = 8;
		while (--offset >= 0)
		{
			if ((1 << offset) & *str)
				kill(pid, SIGUSR2);
			else
				kill(pid, SIGUSR1);
			usleep(500);
		}
		str++;
	}
}

int	main(int ac, char **av)
{
	if (ac != 3)
	{
		write(1, "Error. Input type: <PID> <STRING>\n", 35);
		return (0);
	}
	ft_sender(ft_atoi(av[1]), av[2]);
	signal(SIGUSR2, ft_recive);
	return (0);
}

