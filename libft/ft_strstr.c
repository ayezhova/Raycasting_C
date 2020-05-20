/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayezhova <ayezhova@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/18 06:18:47 by ayezhova          #+#    #+#             */
/*   Updated: 2019/09/20 13:52:28 by ayezhova         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *haystack, const char *needle)
{
	int i;
	int needle_length;
	int needle_i;

	i = -1;
	needle_length = ft_strlen((char *)needle);
	needle_i = 0;
	if (needle[0] == '\0')
		return (char *)(&haystack[i + 1]);
	while (haystack[++i])
	{
		if (haystack[i] == needle[needle_i])
		{
			while (haystack[i + needle_i] == needle[needle_i])
			{
				if (needle_i == needle_length - 1)
					return ((char*)(&haystack[i]));
				needle_i++;
			}
			needle_i = 0;
		}
	}
	return (NULL);
}
