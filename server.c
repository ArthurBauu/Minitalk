/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arbaudou <arbaudou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/29 19:02:52 by arbaudou          #+#    #+#             */
/*   Updated: 2024/12/16 16:55:39 by arbaudou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

volatile sig_atomic_t	g_bit_count = 0;

static void	build_string(char c, siginfo_t *info)
{
	static char	*str = NULL;
	char		new_str[2];
	char		*temp;

	if (c)
	{
		new_str[0] = c;
		new_str[1] = '\0';
		if (!str)
			str = ft_strdup(new_str);
		else
		{
			temp = str;
			str = ft_strjoin(str, new_str);
			free(temp);
		}
	}
	if (c == '\0')
	{
		ft_printf("Message by %d: %s\n", info->si_pid, str);
		free(str);
		str = NULL;
		kill(info->si_pid, SIGUSR2);
	}
}

void	receiver(int sig, siginfo_t *info, void *context)
{
	static char		received_c = 0;
	static int		c_pid = 0;

	(void)context;
	if (c_pid != info->si_pid)
	{
		c_pid = info->si_pid;
		received_c = 0;
	}
	if (sig == SIGUSR1)
		received_c = (received_c << 1) | 1;
	if (sig == SIGUSR2)
		received_c = received_c << 1;
	if (g_bit_count < 8)
		g_bit_count++;
	if (g_bit_count == 8)
	{
		build_string(received_c, info);
		received_c = 0;
		g_bit_count = 0;
	}
	kill(c_pid, SIGUSR1);
}

int	main(int argc, char **argv)
{
	(void)argv;
	if (argc != 1)
		ft_printf("No arg for this program. use [./server]");
	ft_printf("Bienvenue sur le serveur de Arbaudou\n");
	ft_printf("Server PID: %d\n", getpid());
	set_signal(receiver);
	while (1)
		pause();
	return (0);
}
