/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arbaudou <arbaudou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/24 14:52:49 by arbaudou          #+#    #+#             */
/*   Updated: 2024/10/24 15:32:06 by arbaudou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*n_list;
	t_list	*n_elem;

	if (!lst || !f || !del)
		return (NULL);
	n_list = NULL;
	while (lst != NULL)
	{
		n_elem = ft_lstnew(f(lst->content));
		if (!n_elem)
		{
			ft_lstclear(&n_list, del);
			return (NULL);
		}
		ft_lstadd_back(&n_list, n_elem);
		lst = lst->next;
	}
	return (n_list);
}
