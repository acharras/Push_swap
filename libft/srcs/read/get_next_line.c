/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acharras <acharras@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/11 16:22:31 by aurbuche          #+#    #+#             */
/*   Updated: 2021/04/12 14:38:44 by acharras         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/libft.h"

#ifndef BUFFER_SIZE
# define BUFFER_SIZE 8
#endif

int	ft_read_norme(char *buff, char **str, char *temp)
{
	temp = ft_strdup(*str);
	if (!temp)
		return (-1);
	free(*str);
	*str = ft_strjoin(temp, buff);
	if (!*str)
		return (-1);
	free(temp);
	free(buff);
	return (1);
}

int	ft_read(int fd, char **str)
{
	int		ret;
	char	*buff;
	char	*temp;

	buff = ft_malloc(sizeof(char) * (BUFFER_SIZE + 1));
	while (read(fd, buff, BUFFER_SIZE))
	{
		ret = ft_strlen(buff);
		buff[ret] = '\0';
		if (ft_strchr(buff, '\n'))
		{
			if (ft_read_norme(buff, str, temp))
				return (1);
			return (-1);
		}
		temp = ft_strdup(*str);
		free(*str);
		*str = ft_strjoin(temp, buff);
	}
	free(buff);
	return (0);
}

int	ft_fill(int fd, char **str, char **line)
{
	int		ret;
	char	*temp;

	ret = ft_read(fd, str);
	if (ret == -1)
		return (-1);
	if (ret != 0)
	{
		*line = ft_substr(*str, 0, ft_strchr(*str, '\n') - *str);
		temp = ft_strdup(ft_strchr(*str, '\n') + 1);
		free(*str);
		*str = temp;
		return (1);
	}
	else
	{
		*line = ft_substr(*str, 0, ft_strchr(*str, '\0') - *str);
		free(*str);
		*str = NULL;
		return (0);
	}
}

int	get_next_line_norme(char **str, char **line)
{
	char	*temp;

	*line = ft_substr(*str, 0, ft_strchr(*str, '\n') - *str);
	temp = ft_strdup(ft_strchr(*str, '\n') + 1);
	free(*str);
	*str = temp;
	return (1);
}

int	get_next_line(int fd, char **line)
{
	static char	*str = NULL;
	int			ret;

	if (BUFFER_SIZE <= 0 || fd < 0 || !line)
		return (-1);
	if (str == NULL)
		str = ft_strdup("");
	if (!(ft_strchr(str, '\n')))
	{
		ret = ft_fill(fd, &str, line);
		if (ret <= 0)
		{
			free(str);
			return (ret);
		}
		return (1);
	}
	else
		return (get_next_line_norme(&str, line));
}
