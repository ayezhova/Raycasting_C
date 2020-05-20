/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayezhova <ayezhova@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/20 13:57:15 by ayezhova          #+#    #+#             */
/*   Updated: 2019/09/30 14:23:13 by ayezhova         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *src, const char *ndle, size_t len)
{
	unsigned long	i;
	int				needle_length;
	int				needle_i;

	i = -1;
	needle_length = ft_strlen((char *)ndle);
	needle_i = 0;
	if (ndle[0] == '\0')
		return (char *)(&src[i + 1]);
	while (src[++i] && i < len)
	{
		if (src[i] == ndle[needle_i])
		{
			while (src[i + needle_i] == ndle[needle_i] && (i + needle_i) < len)
			{
				if (needle_i == needle_length - 1)
					return ((char*)(&src[i]));
				needle_i++;
			}
			needle_i = 0;
		}
	}
	return (NULL);
}
