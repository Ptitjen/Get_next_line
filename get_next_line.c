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

static int trigger = 0; // 0 : il faut charger buf / 1 : buf deja charge / 2 : fin de fichier atteinte
static char buf [BUFFER_SIZE];
static char	*line = NULL;
static int r = -1;
static int start = 0;

int	ft_charge_buffer(char *buf, int fd)
{
	int		l;
	
	l = read(fd, buf, BUFFER_SIZE);
	if (l == -1)
		return (-1);
	buf[l] = '\0';
	if (trigger == 1)
		trigger = 0;
	return (l);
}

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	if (str == NULL)
		return (0);
	while (str[i] != '\0')
		i ++;
	return (i);
}

char	*ft_strjoin(char *s1, char c)
{
	int	i;
	int	lens1;
	char	*dest;

	i = 0;
	lens1 = ft_strlen(s1);
	dest = malloc(sizeof(char) * (lens1 + 2));
	if (dest == NULL)
		return (NULL);
	if (s1 != NULL)
	{
		while (i < lens1)
		{
			dest[i] = s1[i];
			i ++;
		}
	}
	dest[i] = c;
	i ++;
	dest[i] = '\0';
	free (s1);
	return (dest);
}

char	*get_next_line(int fd)
{
	int	i;
	if (trigger == 0)
	{
		r = ft_charge_buffer(buf, fd);
		if (r ==-1)
			return (NULL);
		i = 0;
		trigger = 1;
	}
	else
	{
		i = start;
		line = NULL;
	}
	while (r != 0) // fin de fichier
	{
		while (buf[i] != '\0') // fin de buf
		{
			while (buf[i] != '\n' && buf[i] != '\0') // remplissage line tant que pas \n
			{
				line = ft_strjoin(line, buf[i]);
				i ++;
			}
			if (buf[i] == '\0' && i == BUFFER_SIZE)//charger buffer suivant
			{
				r = ft_charge_buffer(buf, fd);
				
				i = 0;
			}
			else if (buf[i] == '\n' || (buf[i] == '\0' && i < BUFFER_SIZE))
			{
				line = ft_strjoin(line, buf[i]);
				trigger = 1;
				start = i + 1;
				i = 0;
				return (line);
			}
		}
		start = i;
		trigger = 0;
		return (get_next_line(fd));
	}
	free (line);
	return (NULL);
}
