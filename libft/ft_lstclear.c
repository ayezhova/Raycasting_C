/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayezhova <ayezhova@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/25 21:57:43 by ayezhova          #+#    #+#             */
/*   Updated: 2019/10/21 15:55:52 by ayezhova         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **list)
{
	t_list *link;
	t_list *temp;

	link = *list;
	while (link)
	{
		if (link->next)
			temp = link->next;
		else
			temp = NULL;
		free(link->content);
		free(link);
		link->content_size = 0;
		link = temp;
	}
}
