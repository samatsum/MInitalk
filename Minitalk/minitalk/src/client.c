/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samatsum <samatsum@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/10 15:28:58 by samatsum          #+#    #+#             */
/*   Updated: 2024/11/26 18:18:17 by samatsum         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minitalk.h"

volatile sig_atomic_t	g_signal_received;

static void	ft_confirm(int signal)
{
	(void)signal;
	g_signal_received = 1;
}

void	ft_send_1bytecharacter(int pid, char i)
{
	int	bit;

	bit = 0;
	while (bit < 8)
	{
		g_signal_received = 0;
		if ((i & (0x01 << bit)) != 0)
			kill(pid, SIGUSR1);
		else
			kill(pid, SIGUSR2);
		bit++;
		while (1)
		{
			if (g_signal_received == 1)
				break ;
			usleep(10);
		}
		usleep(100);
	}
}

int	main(int argc, char **argv)
{
	int	serverpid;
	int	i;

	i = 0;
	if (argc == 3)
	{
		serverpid = ft_atoi(argv[1]);
		signal(SIGUSR1, ft_confirm);
		while (argv[2][i] != '\0')
		{
			ft_send_1bytecharacter(serverpid, argv[2][i]);
			i++;
		}
		ft_send_1bytecharacter(serverpid, '\n');
	}
	else
	{
		ft_printf("Error: Wrong Format.\n");
		ft_printf("Correct Format: ./client <ServerPID> <Message>\n");
		exit(1);
	}
	return (0);
}
// #include <unistd.h>
// int main(void)
// {
// 	write(1, "\xE3", 1);
// 	write(1, "\x81", 1);
// 	write(1, "\x82", 1);
// 	return (0);
// }
