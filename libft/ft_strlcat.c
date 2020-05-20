/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayezhova <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/18 14:09:46 by ayezhova          #+#    #+#             */
/*   Updated: 2019/10/03 13:53:12 by ayezhova         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *destination, const char *source, size_t size)
{
	size_t			dest_length;
	size_t			src_length;
	size_t			i;
	int				to_return;

	dest_length = ft_strlen((char *)destination);
	src_length = ft_strlen((char *)source);
	i = 0;
	if (size < dest_length)
		to_return = size + src_length;
	else
		to_return = dest_length + src_length;
	if (size > dest_length)
	{
		while (source[i] != '\0' && i < size - dest_length - 1)
		{
			destination[dest_length + i] = source[i];
			i++;
		}
	}
	destination[dest_length + i] = '\0';
	return (to_return);
}
