/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arbaudou <arbaudou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/29 19:02:52 by arbaudou          #+#    #+#             */
/*   Updated: 2024/12/03 15:28:40 by arbaudou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

volatile sig_atomic_t	g_bit_count = 0;

void	receiver(int sig, siginfo_t *info, void *context)
{
	static char		received_c;
	static int		c_pid;

	(void)context;
	if (c_pid == 0)
		c_pid = info->si_pid;
	if (sig == SIGUSR1)
		received_c |= (0 << g_bit_count);
	if (sig == SIGUSR2)
		received_c |= (1 << g_bit_count);
	g_bit_count++;
	if (g_bit_count == 8)
	{
		if (received_c == '\0')
		{
			ft_putstr("\n");
			if (kill(c_pid, SIGUSR1) == -1)
				ft_putstr("Erreur : impossible d'envoyer un message au client");
			c_pid = 0;
		}
		else
			write(1, &received_c ,1);
		received_c = 0;
		g_bit_count = 0;
	}
}


int	main(void)
{
	struct sigaction	sa;

	ft_printf("Bienvenue sur le serveur de Arbaudou\n");
	ft_printf("Server PID: %d\n", getpid());
	sa.sa_sigaction = &receiver;
	sa.sa_flags = SA_SIGINFO;
	sigemptyset(&sa.sa_mask);
	sigaction(SIGUSR1, &sa, NULL);
	sigaction(SIGUSR2, &sa, NULL);
	while (1)
		pause();
	return (1);
}

/*
#include <fcntl.h>

//Test pour la francinette :
int	main(void)
{
	struct sigaction	sa;
	int					log_fd;

	log_fd = open("server.log", O_WRONLY | O_CREAT | O_TRUNC, 0644);
	if (log_fd < 0)
	{
		perror("Erreur lors de l'ouverture de server.log");
		return (1);
	}
	if (dup2(log_fd, STDOUT_FILENO) < 0 || dup2(log_fd, STDERR_FILENO) < 0)
	{
		perror("Erreur lors de la redirection de la sortie");
		close(log_fd);
		return (1);
	}

	ft_printf("Bienvenue sur le serveur de Arbaudou\n");
	ft_printf("Server PID: %d\n", getpid());

	sa.sa_sigaction = &receiver;
	sa.sa_flags = SA_SIGINFO;
	sigemptyset(&sa.sa_mask);
	sigaction(SIGUSR1, &sa, NULL);
	sigaction(SIGUSR2, &sa, NULL);

	while (1)
		pause();
	close(log_fd);
	return (0);
}
*/


