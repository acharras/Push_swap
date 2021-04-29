/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acharras <acharras@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/11 16:22:31 by acharras          #+#    #+#             */
/*   Updated: 2021/04/29 15:14:50 by acharras         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/libft.h"

#ifndef BUFFER_SIZE
# define BUFFER_SIZE 32
#endif

char	*next_line(char *str, char **line, size_t i, int *end)
{
	char			*tmp;

	if (str && str[i])
	{
		while (str[i] != '\n' && str[i])
			i++;
		if (str[i] == '\n')
		{
			*line = ft_substr(str, 0, i);
			tmp = ft_strdup(str + i + 1);
			ft_strcpy(str, tmp);
			ft_delete(&tmp);
			return (*line);
		}
		else
		{
			*line = ft_substr(str, 0, i);
			tmp = ft_strdup(str + i);
			ft_strcpy(str, tmp);
			ft_delete(&tmp);
			return (*line);
		}
	}
	*end = 1;
	return (NULL);
}

char	*read_line(char **str, char *buf, int fd)
{
	int				ret;
	char			*tmp;

	ret = read(fd, buf, BUFFER_SIZE);
	while (ret != 0)
	{
		if (ret < 0)
			return ((char *) - 1);
		if (!str[fd])
		{
			str[fd] = ft_strdup("");
			if (!str[fd])
				return ((char *) - 1);
		}
		buf[ret] = '\0';
		tmp = ft_strfjoin(str[fd], buf, 1);
		if (!tmp)
			return ((char *) - 1);
		str[fd] = tmp;
		if (ft_strchr(str[fd], '\n'))
			break ;
		ret = read(fd, buf, BUFFER_SIZE);
	}
	return (str[fd]);
}

int	get_next_line(int fd, char **line)
{
	int				end;
	static char		*str[256];
	char			buf[BUFFER_SIZE + 1];

	end = 0;
	if (fd < 0 || BUFFER_SIZE <= 0 || !line || fd >= 256)
	{
		if (*line)
			*line = NULL;
		return (-1);
	}
	str[fd] = read_line(str, buf, fd);
	if (str[fd] == (char *) - 1)
	{
		if (*line)
			*line = NULL;
		return (-1);
	}
	*line = next_line(str[fd], line, 0, &end);
	if (end == 1)
		ft_delete(&str[fd]);
	return (end != 1);
}
