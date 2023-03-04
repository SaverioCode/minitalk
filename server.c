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

#include "lib_minitalk.h"

int	ft_handler(int signo, siginfo_t *info, void *context)
{
	static char	c;
	static int	i;

	printf("i: %d	c: %c	(int)c: %d\n", i, c, (int)c);
	if (signo == SIGUSR2)
	{
		write(1, "signo\n", 6);
		c |= 1 << i;
		printf("%c %d\n", c, (int)c);
	}
	if (++i == 8)
	{
		if (!c)
			exit(0);
		write(1, &c, 1);
		kill(info -> si_pid, SIGUSR2);
		i = 0;
		c = 0;
	}
	write(1, "TEST\n", 5);
	(void)context;
	return (0);
}

int	main(void)
{
	struct sigaction	sa;

	ft_printf("%d\n", getpid());
	// sa = NULL;
	sa.sa_handler = (void *)ft_handler;
	sigaction(SIGUSR1, &sa, NULL);
	sigaction(SIGUSR2, &sa, NULL);
	while (1)
		pause();
	return (0);
}
