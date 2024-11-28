/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samatsum <samatsum@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/10 12:23:20 by samatsum          #+#    #+#             */
/*   Updated: 2024/11/26 16:33:10 by samatsum         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minitalk.h"

void	ft_recceive_1bytecharacter(int signal, siginfo_t *info, void *s)
{
	static int	bit;
	static int	i;

	(void)info;
	(void)s;
	if (signal == SIGUSR1)
		i |= (0x01 << bit);
	bit++;
	if (bit == 8)
	{
		write(1, &i, 1);
		bit = 0;
		i = 0;
	}
	kill(info->si_pid, SIGUSR1);
}

int	main(int argc, char **argv)
{
	int					serverpid;
	struct sigaction	sig;

	(void)argv;
	if (argc != 1)
	{
		ft_printf("Error: Wrong Format.\n");
		ft_printf("Correct Format: ./server\n");
		exit(1);
	}
	serverpid = getpid();
	ft_printf("ServerPID[%d]\n", serverpid);
	ft_printf("Waiting Message from Client\n");
	sig.sa_sigaction = ft_recceive_1bytecharacter;
	sigemptyset(&sig.sa_mask);
	sigaddset(&sig.sa_mask, SIGUSR1);
	sigaddset(&sig.sa_mask, SIGUSR2);
	sig.sa_flags = SA_SIGINFO;
	if (sigaction(SIGUSR1, &sig, NULL) < 0)
		exit(1);
	if (sigaction(SIGUSR2, &sig, NULL) < 0)
		exit(1);
	while (1)
		pause();
	return (0);
}
