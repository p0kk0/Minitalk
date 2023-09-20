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

#include <stdio.h>
#include <signal.h>

int	ft_bit_converter(int pid, char *message)
{
	int		bit_counter;
	char	character;
	
	bit_counter = 1;
	while (bit_counter < 9)
	{
		character = message[counter];
		bit_counter++;
	}
	//tomamos el string, lo descomponemos en bits
	//lo enviamos al pid recibido
	//ascii to int
	int	counter;

	counter = 0;
	while (message[counter])
	{
		sigaction
		counter++;
	}
}

int	main(int argc, char **argv)
{
	int		pid;
	char	*message;

	pid = atoi(argv[1]);
	message = argv[2];
	if (argc != 3)
	{
		ft_printf("Error, número inválido de argumentos.");
		return (0);
	}
	ft_bit_converter(pid, message);
	return (0);
}
