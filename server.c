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

#include <unistd.h>
#include <signal.h>
#include <stdio.h>

void	ft_message_processor(int bit)
{
	int		bit_counter;
	char	character;

	bit_counter = 0;
	while (bit)
	{
		while (bit_counter < 8)
		{
			if (bit == 1)
				character = (character >> bit_counter | 1);
				bit_counter++;
		}
		printf (character);
		character = 0;
		bit_counter = 0;
	}
}

int	main(void)
{
	pid_t	pid;

	pid = getpid();
	printf("PID: %d", pid);
	while (1)
	{
		signal(SIGUSR1, ft_message_processor);
		signal(SIGUSR2, ft_message_processor);
		pause();
	}
	return (0);
}
