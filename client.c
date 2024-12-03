/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arbaudou <arbaudou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/29 19:02:57 by arbaudou          #+#    #+#             */
/*   Updated: 2024/12/03 15:29:53 by arbaudou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#define DEFAULT_SOURCE
#include "minitalk.h"
#include <unistd.h>

void	retour(int sig)
{
	(void)sig;
	ft_printf("Message bien recu par le server.\n");
}

void	send_c(pid_t c_pid, char c)
{
	int	i;

	i = 0;
	while (i < 8)
	{
		if ((c >> i) & 1)
			kill(c_pid, SIGUSR2);
		else
			kill(c_pid, SIGUSR1);
		i++;
		usleep(100);
	}
}

void	send_s(pid_t c_pid, char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		send_c(c_pid, str[i]);
		i++;
	}
	send_c(c_pid, '\0');
}

int	main(int argc, char **argv)
{
	struct sigaction	sa;
	int					c_pid;

	if (argc != 3)
	{
		ft_printf("Usage: ./client [SERVER_PID] [MESSAGE]\n");
		return (0);
	}
	c_pid = atoi(argv[1]);
	if (c_pid <= 0)
	{
		ft_printf("ERROR: invalid PID\n");
		return (0);
	}
	ft_printf("__PID: %d\n", getpid());
	sa.sa_handler = &retour;
	sa.sa_flags = 0;
	sigemptyset(&sa.sa_mask);
	sigaction(SIGUSR1, &sa, NULL);
	send_s(c_pid, argv[2]);
	return (0);
}
