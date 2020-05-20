/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstend.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayezhova <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/25 22:09:27 by ayezhova          #+#    #+#             */
/*   Updated: 2019/09/25 22:10:13 by ayezhova         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_lstend(t_list **alst, t_list *new)
{
	t_list *temp;

	temp = *alst;
	if (alst != NULL && new != NULL)
	{
		while (temp->next)
		{
			temp = temp->next;
		}
		temp->next = new;
		return (1);
	}
	return (0);
}
