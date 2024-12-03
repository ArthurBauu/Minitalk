/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arbaudou <arbaudou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/22 17:18:38 by arbaudou          #+#    #+#             */
/*   Updated: 2024/11/30 22:04:31 by arbaudou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# define BASE_TEN "0123456789"
# define LHEXBASE "0123456789abcdef"
# define UHEXBASE "0123456789ABCDEF"

# include <unistd.h>
# include <stdarg.h>

int		ft_printf(const char *format, ...);
int		ft_putinbr(int nb);
int		ft_putnbr_base(unsigned int nb, char *base);
int		ft_putadrr_base(void *n, char *base);
int		ft_putchar(int c);
int		ft_putstr(char *str);
int		ft_strplen(char const *s);

#endif