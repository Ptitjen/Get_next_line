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

int	ft_is_a_line(char *s)
{
	int	i;

	i = 0;
	if (s == NULL)
		return (0);
	while (s[i] != '\0')
	{
		if (s[i] == '\n')
			return (1);
		i ++;
	}
	return (0);
}

char	*ft_charge_buffer(int fd, char *buf, char *tmp, char *next)
{
	int	r;

	r = -1;
	while (r != 0)
	{
		next = tmp;
		r = read(fd, buf, BUFFER_SIZE);
		if (r == -1)
		{
			free (buf);
			return (NULL);
		}
		buf[r] = '\0';
		if (next == NULL)
		{
			next = malloc(sizeof(char));
			next[0] = '\0';
		}
		tmp = ft_strjoin(next, buf);
		free (next);
		if (ft_is_a_line(tmp) == 1)
			break ;
	}
	free (buf);
	return (tmp);
}

char	*get_next_line(int fd)
{
	static char	*tmp;
	char		*line;
	char		*next;
	char		*buf;

	next = NULL;
	if (fd < 0 || fd > 1024 || BUFFER_SIZE <= 0)
		return (NULL);
	buf = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (buf == NULL)
		return (NULL);
	tmp = ft_charge_buffer(fd, buf, tmp, next);
	if (tmp == NULL)
		return (NULL);
	line = ft_fill_line(tmp);
	tmp = ft_copy_temp(tmp);
	return (line);
}
