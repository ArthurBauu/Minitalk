/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arbaudou <arbaudou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/23 14:43:46 by arbaudou          #+#    #+#             */
/*   Updated: 2024/10/24 21:08:28 by arbaudou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	is_a_sep(char c, char sep)
{
	if (sep == c)
		return (1);
	return (0);
}

static int	count_words(char *str, char sep)
{
	int	i;
	int	nbw;

	i = 0;
	nbw = 0;
	if (!(is_a_sep(str[i], sep)) && str[i])
		nbw++;
	while (str[i])
	{
		if (is_a_sep(str[i], sep) && str[i + 1] && !is_a_sep(str[i + 1], sep))
			nbw++;
		i++;
	}
	return (nbw);
}

static char	**split_str(char **tab, char *str, char sep, int *index)
{
	int	len;
	int	i;

	i = 0;
	while (str[i] && !is_a_sep(str[i], sep))
		i++;
	len = i;
	tab[*index] = malloc(sizeof(char) * (len + 1));
	if (!tab[*index])
		return (NULL);
	i = 0;
	while (i < len)
	{
		tab[*index][i] = str[i];
		i++;
	}
	tab[*index][i] = '\0';
	(*index)++;
	return (tab);
}

static char	**create_tab(char **tab, char *str, char sep, int nbw)
{
	int	i;
	int	index;

	i = 0;
	index = 0;
	while (str[i] && index < nbw)
	{
		if (str[i] && is_a_sep(str[i], sep))
			i++;
		if (str[i] && !is_a_sep(str[i], sep))
		{
			split_str(tab, &str[i], sep, &index);
			while (str[i] && !is_a_sep(str[i], sep))
				i++;
		}
	}
	tab[nbw] = NULL;
	return (tab);
}

char	**ft_split(char *s, char c)
{
	char	**tab;
	int		nbw;

	if (!s)
		return (NULL);
	nbw = count_words(s, c);
	tab = malloc(sizeof(char *) * (nbw + 1));
	if (!tab)
		return (NULL);
	create_tab(tab, s, c, nbw);
	return (tab);
}
