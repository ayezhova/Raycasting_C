/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_countdigits_nosign.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayezhova <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/13 15:39:18 by ayezhova          #+#    #+#             */
/*   Updated: 2020/01/13 15:51:12 by ayezhova         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_countdigits_nosign(int n)
{
	int count;
	int sign;

	sign = 0;
	count = 0;
	if (n == 0)
		return (1);
	if (n == -2147483648)
		return (11);
	if (n < 0)
	{
		sign = -1;
		n = n * -1;
	}
	while (n > 0)
	{
		n = n / 10;
		count++;
	}
	if (sign == -1)
		count++;
	return (count);
}
