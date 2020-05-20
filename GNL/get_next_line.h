/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anastasiyayezhova <anastasiyayezhova@st    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/18 14:58:00 by ayezhova          #+#    #+#             */
/*   Updated: 2020/05/16 15:26:46 by anastasiyay      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# define BUFF_SIZE 48

# include <string.h>
# include <stdlib.h>
# include <unistd.h>
# include "../libft/libft.h"

int		get_next_line(const int fd, char **line);

#endif
