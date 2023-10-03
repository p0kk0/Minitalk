/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: felsanch <felsanch@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/17 20:13:24 by felsanch          #+#    #+#             */
/*   Updated: 2023/09/19 20:33:11 by felsanch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	ft_bit_converter(int pid, char *message)
{
	int		bit_counter;
	char	character;

	while (*message)
	{
		bit_counter = 8;
		character = *message;
		while (bit_counter--)
		{
			if (character >> bit_counter & 1)
				kill(pid, SIGUSR2);
			else
				kill(pid, SIGUSR1);
			usleep(30);
		}
		message++;
	}
}

int	main(int argc, char **argv)
{
	int		pid;
	char	*message;

	pid = ft_atoi(argv[1]);
	message = argv[2];
	if (argc != 3)
	{
		ft_printf("Error, invalid number of arguments.");
		return (EXIT_FAILURE);
	}
	ft_bit_converter(pid, message);
	return (0);
}
