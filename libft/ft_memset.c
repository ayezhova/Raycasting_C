/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayezhova <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/20 05:49:08 by ayezhova          #+#    #+#             */
/*   Updated: 2019/09/20 05:49:45 by ayezhova         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *str, int c, size_t n)
{
	unsigned char *str_ptr;

	str_ptr = (unsigned char *)str;
	while (n--)
	{
		*str_ptr = c;
		str_ptr++;
	}
	return (str);
}
