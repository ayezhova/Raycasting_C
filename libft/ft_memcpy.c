/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayezhova <ayezhova@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/25 21:02:08 by ayezhova          #+#    #+#             */
/*   Updated: 2019/10/02 23:21:09 by ayezhova         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t cnt)
{
	size_t			i;
	char			*dest_ptr;
	char			*src_ptr;

	i = 0;
	if (!dst && !src && cnt > 0)
		return (NULL);
	dest_ptr = dst;
	src_ptr = (char *)src;
	while (i < cnt)
	{
		dest_ptr[i] = src_ptr[i];
		i++;
	}
	return (dst);
}
