/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayezhova <ayezhova@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/25 21:03:48 by ayezhova          #+#    #+#             */
/*   Updated: 2019/10/02 23:24:45 by ayezhova         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dest, const void *src, int c, size_t count)
{
	size_t			i;
	unsigned char	*dest_ptr;
	unsigned char	*src_ptr;

	i = 0;
	dest_ptr = (unsigned char *)dest;
	src_ptr = (unsigned char *)src;
	c = (unsigned char)c;
	while (i < count)
	{
		*dest_ptr = src_ptr[i];
		if (*dest_ptr == c)
		{
			dest_ptr++;
			return (dest_ptr);
		}
		i++;
		dest_ptr++;
	}
	return (NULL);
}
