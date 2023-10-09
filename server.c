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

#include "minitalk.h"

void	ft_message_processor(int signal)
{
	static int	bit_counter = 0;
	static char	character = 0;

	if (signal == SIGUSR2)
		character = character | (1 << (7 - bit_counter));
	bit_counter++;
	if (bit_counter == 8)
	{
		ft_putchar(character);
		bit_counter = 0;
		character = 0;
	}
}

int	main(void)
{
	pid_t	pid;

	pid = getpid();
	ft_printf("PID: %d\n", pid);
	signal(SIGUSR1, ft_message_processor);
	signal(SIGUSR2, ft_message_processor);
	while (1)
		pause();
	return (0);
}
