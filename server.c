/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgarzi-c <fgarzi-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/03 01:08:52 by fgarzi-c          #+#    #+#             */
/*   Updated: 2023/03/04 21:19:17 by fgarzi-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf/ft_printf.h"

int	ft_handler(int signo, siginfo_t *info, void *context)
{
	static char	c;
	static int	i;

	if (signo == SIGUSR2)
		c |= 1 << i;
	if (++i == 8)
	{
		if (!c)
		{
			write(1, "\n", 1);
			kill(info->si_pid, SIGUSR2);
		}
		write(1, &c, 1);
		i = 0;
		c = 0;
	}
	(void)context;
	return (0);
}

int	main(void)
{
	struct sigaction	sa;

	ft_printf("%d\n", getpid());
	sa.sa_flags = SA_SIGINFO;
	sa.sa_sigaction = (void *)ft_handler;
	sigaction(SIGUSR1, &sa, NULL);
	sigaction(SIGUSR2, &sa, NULL);
	while (1)
		pause();
	return (0);
}
