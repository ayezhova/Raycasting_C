/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayezhova <ayezhova@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/25 20:33:14 by ayezhova          #+#    #+#             */
/*   Updated: 2019/10/03 13:52:27 by ayezhova         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list *elem;

	if (!lst)
		return (NULL);
	elem = f(lst);
	while ((lst = lst->next))
	{
		if (!ft_lstend(&elem, f(lst)))
			return (NULL);
	}
	return (elem);
}
