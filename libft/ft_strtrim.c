/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayezhova <ayezhova@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/20 08:04:28 by ayezhova          #+#    #+#             */
/*   Updated: 2019/10/02 23:32:09 by ayezhova         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*set_chars(char const *s, int i, int ws_front, int ws_end)
{
	int		j;
	char	*str;

	j = 0;
	if (!(str = (char*)malloc((sizeof(*s) * (i - ws_front - ws_end) + 1))))
		return (NULL);
	while (j + ws_front < i - ws_end)
	{
		str[j] = s[ws_front + j];
		j++;
	}
	str[j] = '\0';
	return (str);
}

static char	*ws_count(char const *s)
{
	int		i;
	int		ws_front;
	int		ws_end;
	char	*str;

	i = 0;
	ws_front = 0;
	ws_end = 0;
	while (s[i] == ' ' || s[i] == '\n' || s[i] == '\t')
	{
		i++;
		ws_front++;
	}
	while (s[i] != '\0')
	{
		if (s[i] == ' ' || s[i] == '\n' || s[i] == '\t')
			ws_end++;
		else
			ws_end = 0;
		i++;
	}
	str = set_chars(s, i, ws_front, ws_end);
	return (str);
}

char		*ft_strtrim(char const *s)
{
	char *str;

	str = ws_count(s);
	return (str);
}
