/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayezhova <ayezhova@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/21 04:10:48 by ayezhova          #+#    #+#             */
/*   Updated: 2019/10/03 17:40:28 by ayezhova         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "libft.h"

static int		count_digits(int n, int sign)
{
	int count;

	count = 0;
	if (n == 0)
		return (1);
	while (n > 0)
	{
		n = n / 10;
		count++;
	}
	if (sign == -1)
		count++;
	return (count);
}

static void		set_sign(int sign, char *str)
{
	if (sign == -1)
		str[0] = '-';
}

char			*ft_itoa(int n)
{
	int		sign;
	char	*str;
	int		i;
	int		digits;

	i = -1;
	sign = 0;
	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	if (n < 0)
	{
		sign = -1;
		n = n * -1;
	}
	digits = count_digits(n, sign);
	if (!(str = (char*)malloc((sizeof(*str) * digits + 1))))
		return (NULL);
	while (++i < digits + sign)
	{
		str[digits - 1 - i] = (n % 10) + '0';
		n = n / 10;
	}
	set_sign(sign, str);
	str[digits] = '\0';
	return (str);
}
