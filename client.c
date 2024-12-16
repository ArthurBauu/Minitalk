/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arbaudou <arbaudou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/29 19:02:57 by arbaudou          #+#    #+#             */
/*   Updated: 2024/12/16 16:51:53 by arbaudou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#define DEFAULT_SOURCE
#include "minitalk.h"
#include <unistd.h>

volatile sig_atomic_t	g_bit_sent = 0;

void	retour(int sig, siginfo_t *info, void *context)
{
	(void)info;
	(void)context;
	if (sig == SIGUSR1)
		g_bit_sent = 1;
	else if (sig == SIGUSR2)
		ft_printf("Well received");
}

void	send_c(int c_pid, char *c_bits)
{
	int	i;

	i = 0;
	while (c_bits[i])
	{
		g_bit_sent = 0;
		if (c_bits[i] == '1')
			kill(c_pid, SIGUSR1);
		else
			kill(c_pid, SIGUSR2);
		while (!g_bit_sent)
			pause();
		i++;
	}
	free(c_bits);
}

void	send_s(pid_t c_pid, char *str)
{
	int	i;

	i = 0;
	while (i <= ft_strlen(str))
	{
		send_c(c_pid, char_to_bit(str[i]));
		i++;
	}
}

int	main(int argc, char **argv)
{
	if (argc != 3)
	{
		ft_printf("Usage: ./client [SERVER_PID] [MESSAGE]\n");
		return (1);
	}
	if (!argv[2] || argv[2][0] == '\0')
	{
		ft_printf("ERROR: message empty\n");
		return (1);
	}
	if (ft_atoi(argv[1]) <= 0 || kill(ft_atoi(argv[1]), 0))
	{
		ft_printf("ERROR: invalid PID\n");
		return (1);
	}
	ft_printf("__PID: %d\n", getpid());
	set_signal(retour);
	send_s(ft_atoi(argv[1]), argv[2]);
	return (0);
}
