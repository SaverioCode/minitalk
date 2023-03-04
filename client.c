/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgarzi-c <fgarzi-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/03 01:11:18 by fgarzi-c          #+#    #+#             */
/*   Updated: 2023/03/04 02:14:49 by fgarzi-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib_minitalk.h"

void	ft_sender(int pid, char *str)
{
	int	offset;

	// this goes to the server part
	// if (str[0] = 37 && str[1] == 64 && !str[2])
	// {
	// 	write(1, "Bye!\n", 5);
	// 	exit(0);
	// }
	while (*str)
	{
		offset = -1;
		while (++offset < 8)
		{
			if ((1 << offset) & *str)
				kill(pid, SIGUSR1);
			else
				kill(pid, SIGUSR2);
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
	return (0);
}

