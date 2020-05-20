/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayezhova <ayezhova@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/09 13:29:22 by ayezhova          #+#    #+#             */
/*   Updated: 2020/01/09 21:03:57 by ayezhova         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	count_digits(long int n, int base)
{
	int count;

	count = 0;
	if (n == 0)
		return (1);
	while (n > 0)
	{
		n = n / base;
		count++;
	}
	return (count);
}

static void	check_sign(long int *num, int *sign)
{
	(*sign) = 0;
	if ((*num) < 0)
	{
		(*sign) = 1;
		(*num) = (*num) * -1;
	}
}

char		*ft_itoa_base(long int num, int base, int lower, int *len)
{
	char	*str;
	int		i;
	char	*possib;
	int		sign;

	check_sign(&num, &sign);
	if (lower == 1)
		possib = ft_strdup("0123456789abcdef");
	else
		possib = ft_strdup("0123456789ABCDEF");
	i = -1;
	*len = count_digits(num, base) + sign;
	if (!(str = (char*)malloc((sizeof(*str) * *len + 1 + sign))))
		return (NULL);
	str[*len - 1] = '\0';
	while (++i < *len)
	{
		str[*len - 1 - i] = possib[num % base];
		num = num / base;
	}
	if (sign == 1)
		str[0] = '-';
	free(possib);
	return (str);
}
