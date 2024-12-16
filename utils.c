/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arbaudou <arbaudou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/16 15:07:32 by arbaudou          #+#    #+#             */
/*   Updated: 2024/12/16 16:54:37 by arbaudou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	set_signal(void (*receiver)(int, siginfo_t *, void *))
{
	struct sigaction	sa;

	sigemptyset(&sa.sa_mask);
	sa.sa_sigaction = receiver;
	sa.sa_flags = SA_SIGINFO;
	sigaction(SIGUSR1, &sa, NULL);
	sigaction(SIGUSR2, &sa, NULL);
}

char	*char_to_bit(const char octet)
{
	char	*bit;
	int		i;

	bit = malloc(sizeof(char) * (8 + 1));
	if (!bit)
		return (NULL);
	i = 7;
	while (i >= 0)
	{
		if (octet & (1 << i))
			bit[7 - i] = '1';
		else
			bit[7 - i] = '0';
		i--;
	}
	bit[8] = '\0';
	return (bit);
}
