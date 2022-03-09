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

static int	g_trigger = 0; // 0 : charger buf / 1 : buf OK / 2 : EOF
static char	g_buf [BUFFER_SIZE + 1];
static char	*g_line = NULL;
static int	g_r = -1;
static int	g_start = 0;

static int	ft_charge_buffer(int fd)
{
	int	l;

	l = read(fd, g_buf, BUFFER_SIZE);
	if (l == -1)
		return (-1);
	g_buf[l] = '\0';
	if (g_trigger == 1)
		g_trigger = 0;
	return (l);
}

//renvoie -1 si EOF ou erreur lecture / charge nouveau buf SB (2)
static int	ft_trigger_or_charge(int fd, int choice)
{
	if (choice == 1)
	{
		if (g_trigger == 0)
		{
			g_r = ft_charge_buffer(fd);
			if (g_r == -1)
				return (-1);
			g_trigger = 1;
			return (0);
		}
		else if (g_trigger == 1)
		{
			g_line = NULL;
			return (g_start);
		}
		if (g_trigger == 2)
			return (-1);
		return (0);
	}
	else
	{
		g_r = ft_charge_buffer(fd);
		return (0);
	}
}

//fin fichier dans ce buf
static int	ft_eol_eof(int i)
{
	if ((g_buf[i] == '\0' && i < BUFFER_SIZE))
		g_trigger = 2;
	if (g_buf[i] == '\n')
		g_trigger = 1;
	g_line = ft_strjoin(g_line, g_buf[i]);
	g_start = i + 1;
	i = 0;
	return (i);
}

// copie char par char dans line EOB ou jusque prochaine nl
static int	ft_find_next_nl(int i)
{
	while (g_buf[i] != '\n' && g_buf[i] != '\0')
	{
		g_line = ft_strjoin(g_line, g_buf[i]);
		i ++;
	}
	return (i);
}

//mettre bloqueur de mauvais fd?
char	*get_next_line(int fd)
{
	int	i;

	i = ft_trigger_or_charge(fd, 1);
	while (g_r != 0 && i != -1)
	{
		while (g_buf[i] != '\0')
		{
			i = ft_find_next_nl(i);
			if (g_buf[i] == '\0' && i == BUFFER_SIZE)
				i = ft_trigger_or_charge(fd, 2);
			else
			{
				i = ft_eol_eof(i);
				return (g_line);
			}
		}
		g_start = i;
		g_trigger = 0;
		if (g_line != NULL)
			return (g_line);
		return (get_next_line(fd));
	}
	return (NULL);
}
