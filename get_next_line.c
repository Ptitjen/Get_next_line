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
#include<stdio.h>

/*static char *ft_charge_buffer(int fd, char *buf)
{
	int	r;

	r = read(fd, buf, BUFFER_SIZE);

	if (r == -1 || r == 0)
		return (NULL);
	buf[r] = '\0';
	return (buf);
}*/

char	*get_next_line(int fd)
{
	static char	*tmp;
	char 		*line;
	static int 	r;
	char	*next;

	if (fd < 0 || fd > 1024 || BUFFER_SIZE <= 0)
		return (NULL);

	if (tmp == NULL)
	{
		tmp = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	//	printf("tmp1 : %p", tmp);
		r = read(fd,tmp, BUFFER_SIZE);
		if (r == -1 || r == 0)
		{
			free(tmp);
			tmp = NULL;
				return (NULL);
		}
		tmp[r] = '\0';

	}

	line = ft_fill_line(tmp);
	
	tmp = ft_copy_temp(tmp);

	
	while (r > 0)
	{
		if (tmp)
			return (line);
		if (tmp == NULL)
		{
			
			if (r > 0)
			{
				free (tmp);
				tmp = malloc(sizeof(char) * (BUFFER_SIZE + 1));
				//printf("tmp2 : %p", tmp);
				r = read(fd,tmp, BUFFER_SIZE);
				if (r == -1 )
				{
					free(tmp);
					tmp = NULL;
					return (NULL);
				}
				tmp[r] = '\0';
				next = ft_fill_line(tmp);
				
				line = ft_strjoin(line, next);
				
				tmp = ft_copy_temp(tmp);
			}
		}
	}
	//free(tmp);
	return(line);
}



