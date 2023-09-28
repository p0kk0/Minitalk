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
	int		bit_counter;
	char	character;

	bit_counter = 8;
	character = 0;
	if (signal == SIGUSR2)
		character = character 
	bit_counter--;
	if (bit_counter == 0)
	{
		ft_printf("%c", character);
		bit_counter = 0;
		character = 0;
	}
}

int	main(void)
{
	pid_t	pid;

	pid = getpid();
	ft_printf("PID: %d", pid);
	while (1)
	{
		signal(SIGUSR1, ft_message_processor);
		signal(SIGUSR2, ft_message_processor);
		pause();
	}
	return (0);
}
