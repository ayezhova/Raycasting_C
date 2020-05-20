/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayezhova <ayezhova@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/20 04:30:09 by ayezhova          #+#    #+#             */
/*   Updated: 2019/09/20 04:46:34 by ayezhova         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_bzero(void *s, size_t n)
{
	unsigned char *s_ptr;
	unsigned long i;

	i = 0;
	s_ptr = (unsigned char*)s;
	while (i < n)
	{
		s_ptr[i] = 0;
		i++;
	}
}
