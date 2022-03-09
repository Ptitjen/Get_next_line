/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeulliot <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/03 13:41:11 by jeulliot          #+#    #+#             */
/*   Updated: 2022/03/03 13:41:13 by jeulliot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"get_next_line.h"

char	*get_next_line(int fd)
{
	int	i;
	static char	*line = NULL;
	static t_buf buffer;

	if (fd < 0 || fd > 1024 || BUFFER_SIZE <= 0)
		return (NULL);
	i = 0;
	if (buffer.trigger == 0)
	{
		buffer.r = read(fd, buffer.buf, BUFFER_SIZE);
		if (buffer.r == -1)
			return (NULL);
		buffer.buf[buffer.r] = '\0';
		if (buffer.r == -1)
			i = -1;
		buffer.trigger = 1;
	}
	else if (buffer.trigger == 1)
	{
		line = NULL;
		i = buffer.start;
	}
	if (buffer.trigger == 2)
		i = - 1;
	if (fd == 0 && i == -1)
		return (NULL);
	while ((buffer.r > 0 && i != -1))
	{
		while (buffer.buf[i] != '\0')
		{
			while (buffer.buf[i] != '\n' && buffer.buf[i] != '\0')
			{
				line = ft_strjoin(line, buffer.buf[i]);
				i ++;
			}
			if (buffer.buf[i] == '\0' && i == BUFFER_SIZE)
			{
				buffer.r = read(fd, buffer.buf, BUFFER_SIZE);
				if (buffer.r == -1)
					return (NULL);
				buffer.buf[buffer.r] = '\0';
				if (buffer.trigger == 1)
					buffer.trigger = 0;
				i = 0;
			}
			else
			{
				if ((buffer.buf[i] == '\0' && i < BUFFER_SIZE))
					buffer.trigger = 2;
				if (buffer.buf[i] == '\n')
					buffer.trigger = 1;
				line = ft_strjoin(line, buffer.buf[i]);
				buffer.start = i + 1;
				i = 0;
				return (line);
			}
		}
		buffer.start = i;
		buffer.trigger = 0;
		if (line != NULL)
			return (line);
		return (get_next_line(fd));
	}
	return (NULL);
}
