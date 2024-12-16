/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arbaudou <arbaudou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/29 19:10:54 by arbaudou          #+#    #+#             */
/*   Updated: 2024/12/16 16:54:03 by arbaudou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H
# define _POSIX_SOURCE 1
# define _POSIX_C_SOURCE 199309L

# include <signal.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <fcntl.h>
# include "libft/libft.h"
# include "printf/ft_printf.h"

void	set_signal(void (*receiver)(int, siginfo_t *, void *));
char	*char_to_bit(const char octet);

#endif
