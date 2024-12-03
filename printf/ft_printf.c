/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arbaudou <arbaudou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/22 17:18:35 by arbaudou          #+#    #+#             */
/*   Updated: 2024/11/30 22:03:25 by arbaudou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	char_form(const char c, va_list args)
{
	int	len;

	if (c == 'c')
		len = ft_putchar(va_arg(args, int));
	if (c == 's')
		len = ft_putstr(va_arg(args, char *));
	if (c == 'i' || c == 'd')
		len = ft_putinbr(va_arg(args, int));
	if (c == 'u')
		len = ft_putnbr_base(va_arg(args, long), BASE_TEN);
	if (c == '%')
		len = ft_putchar('%');
	if (c == 'x')
		len = ft_putnbr_base(va_arg(args, unsigned int), LHEXBASE);
	if (c == 'X')
		len = ft_putnbr_base(va_arg(args, unsigned int), UHEXBASE);
	if (c == 'p')
		len = ft_putadrr_base(va_arg(args, void *), LHEXBASE);
	return (len);
}

int	ft_printf(const char *format, ...)
{
	const char	*str = format;
	int			i;
	char		c;
	va_list		args;
	int			len;

	va_start(args, format);
	i = 0;
	len = 0;
	while (str[i])
	{
		if (str[i] == '%' && str[i + 1])
		{
			i++;
			c = str[i];
			len += char_form(c, args);
		}
		else
			len += ft_putchar(str[i]);
		i++;
	}
	va_end (args);
	return (len);
}