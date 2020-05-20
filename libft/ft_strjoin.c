/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayezhova <ayezhova@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/20 07:33:17 by ayezhova          #+#    #+#             */
/*   Updated: 2019/09/25 21:54:27 by ayezhova         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*str;
	int		str_len;
	int		s1_len;
	int		i;

	i = 0;
	s1_len = ft_strlen((char *)s1);
	str_len = ft_strlen((char*)s1) + ft_strlen((char*)s2);
	if (!(str = (char*)malloc((sizeof(*str) * str_len + 1))))
		return (NULL);
	ft_strcpy(str, (char*)s1);
	while ((s1_len + i < str_len))
	{
		str[s1_len + i] = s2[i];
		i++;
	}
	str[str_len] = '\0';
	return (str);
}
