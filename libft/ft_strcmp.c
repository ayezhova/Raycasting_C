/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayezhova <ayezhova@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/18 06:27:09 by ayezhova          #+#    #+#             */
/*   Updated: 2019/09/26 21:53:33 by ayezhova         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_strcmp(const char *str1, const char *str2)
{
	int i;

	i = 0;
	while (str1[i] != '\0' && str2[i] != '\0')
	{
		if (str1[i] == str2[i])
			i++;
		else
		{
			return ((unsigned char)str1[i] - (unsigned char)str2[i]);
		}
	}
	if (str1[i] != '\0' || str2[i] != '\0')
		return ((unsigned char)str1[i] - (unsigned char)str2[i]);
	else
		return (0);
}
