/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayezhova <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/20 13:54:30 by ayezhova          #+#    #+#             */
/*   Updated: 2019/09/20 13:54:58 by ayezhova         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char	*ptr;
	char	*return_ptr;
	int		pointing;

	pointing = 0;
	ptr = (char*)s;
	while (*ptr != '\0')
	{
		if (*ptr == c)
		{
			return_ptr = ptr;
			pointing = 1;
		}
		ptr++;
	}
	if (*ptr == '\0' && c == '\0')
		return (ptr);
	if (pointing == 1)
		return (return_ptr);
	else
		return (NULL);
}
