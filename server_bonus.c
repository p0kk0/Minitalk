/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: felsanch <felsanch@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/17 18:37:28 by felsanch          #+#    #+#             */
/*   Updated: 2023/09/19 20:04:43 by felsanch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk_bonus.h"

void	ft_message_processor(int signal, siginfo_t *info, void *context)
{
	static int	bit_counter = 0;
	static char	character = 0;

	(void)context;
	if (signal == SIGUSR2)
		character = character | (1 << (7 - bit_counter));
	bit_counter++;
	if (bit_counter == 8)
	{
		ft_putchar(character);
		bit_counter = 0;
		character = 0;
		kill(info->si_pid, SIGUSR1);
	}
}

int	main(void)
{
	pid_t				pid;
	struct sigaction	info;

	pid = getpid();
	ft_printf("PID: %d\n", pid);
	info.sa_sigaction = ft_message_processor;
	info.sa_flags = 0;
	sigaction(SIGUSR1, &info, NULL);
	sigaction(SIGUSR2, &info, NULL);
	while (1)
		pause();
	return (0);
}
