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

char	*ft_message_processor()
{
	//Procesamos los bits recibidos, cuando son 8, escribimos el char
	//int to ascii
}

int	main(void)
{
	pid_t	pid;

	pid = getpid();
	printf("PID: %d", pid);
	while (1)
	{
		if (ft_bit_converter == 0)
			ft_message_processor();
		else if (ft_bit_converter == 1)
			ft_message_processor();
	}
	return (0);
}
