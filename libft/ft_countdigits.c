/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_countdigits.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayezhova <ayezhova@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/09 21:48:25 by ayezhova          #+#    #+#             */
/*   Updated: 2019/10/09 21:51:03 by ayezhova         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_countdigits(int n, int sign)
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
