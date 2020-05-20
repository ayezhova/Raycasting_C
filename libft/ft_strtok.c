/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtok.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayezhova <ayezhova@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/11 17:22:12 by ayezhova          #+#    #+#             */
/*   Updated: 2019/10/14 16:14:57 by ayezhova         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

char	*ft_strtok(char *str, const char *delim)
{
	static char	*stack;
	static int	letters;
	char		*ptr;
	int			temp;

	if (str != NULL)
	{
		stack = ft_strdup(str);
		letters = 0;
	}
	if (stack[letters] == '\0')
		return (NULL);
	temp = letters;
	ptr = stack;
	while (stack[letters] != delim[0] && stack[letters] != '\0')
		letters++;
	if (stack[letters] != '\0')
	{
		stack[letters] = '\0';
		letters++;
	}
	return (ptr + temp);
}
