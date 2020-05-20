/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayezhova <ayezhova@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/25 21:06:10 by ayezhova          #+#    #+#             */
/*   Updated: 2019/10/02 23:25:22 by ayezhova         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned long i;
	unsigned char *s_ptr;

	s_ptr = (unsigned char *)s;
	i = 0;
	while (i < n)
	{
		if (*s_ptr == (unsigned char)c)
		{
			return (s_ptr);
		}
		s_ptr++;
		i++;
	}
	return (NULL);
}
