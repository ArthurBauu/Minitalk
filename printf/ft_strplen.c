/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strplen.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arbaudou <arbaudou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/30 22:02:13 by arbaudou          #+#    #+#             */
/*   Updated: 2024/11/30 23:09:41 by arbaudou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_strplen(char const *s)
{
	size_t	size;

	size = 0;
	while (s[size])
		size++;
	return (size);
}
