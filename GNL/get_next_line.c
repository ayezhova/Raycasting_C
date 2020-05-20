/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayezhova <ayezhova@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/18 13:57:40 by ayezhova          #+#    #+#             */
/*   Updated: 2019/11/18 17:56:43 by ayezhova         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	set_line(char **remainders, int fd, char **line)
{
	char	*temp;
	int		length;
	int		new_line;

	length = ft_strlen(remainders[fd]);
	new_line = firstoccur(remainders[fd], '\n');
	if (new_line != -1)
		length = new_line;
	*line = ft_strsub(remainders[fd], 0, length);
	if (new_line != -1)
	{
		if (remainders[fd][length + 1] != '\0')
		{
			temp = ft_strdup(remainders[fd] + length + 1);
			free(remainders[fd]);
			remainders[fd] = temp;
		}
		else
			ft_strdel(&remainders[fd]);
	}
	else
		ft_strdel(&remainders[fd]);
}

int		get_next_line(const int fd, char **line)
{
	char		buf[BUFF_SIZE + 1];
	static char	*remainders[4096];
	int			num;
	char		*temp;

	if (!line || fd < 0 || fd >= 4096 || read(fd, buf, 0) < 0 || BUFF_SIZE <= 0)
		return (-1);
	while ((num = read(fd, buf, BUFF_SIZE)) > 0)
	{
		buf[num] = '\0';
		if (remainders[fd] == NULL)
			remainders[fd] = ft_strnew(1);
		temp = ft_strjoin(remainders[fd], buf);
		free(remainders[fd]);
		remainders[fd] = temp;
		if (ft_strchr(buf, '\n'))
			break ;
	}
	if (num == 0 && (remainders[fd] == NULL || remainders[fd][0] == '\0'))
		return (0);
	set_line(remainders, fd, line);
	return (1);
}
