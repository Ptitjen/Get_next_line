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

static int count = 1;
static int start = 0;
static int i = 0;
static char *buf = NULL;
static int r = -1;

// marche uniquement quand buffer >= r
// => faire strcat dans buf plus grand pour ajouter la suite en bout de chaine
// ds strcat : cpoie dans char temporaire, free uis remalloc dans plus grand?

char	*get_next_line(int fd)
{
	char	*line;
	//int		r;
	int 	n;

	//r = -1;
	if (!buf)
	{
		buf = malloc(sizeof(char) * (BUFFER_SIZE + 1));
		if (buf == NULL) // erreur malloc
			return (NULL);
		r = read(fd, buf, BUFFER_SIZE);
		if ((r == -1 || r == 0) && buf != NULL) //echec lecture ou fichier vide
		{
			free(buf);
			buf = NULL;
			return (NULL);
		}
		buf[r] = '\0';
	}
	printf("\nr : %d\n", r);
	printf("buffer : %d\n", BUFFER_SIZE);
	if (r > BUFFER_SIZE)
	{
		r = read(fd, buf, BUFFER_SIZE);
	}

	if (i >= BUFFER_SIZE || !buf[i]) // fin de fichier
	{
		if (buf)
			free (buf);
		return (NULL);
	}
	printf("buf : %s\n", buf);
	n = 0;
	while (n!= count /*&& i <= BUFFER_SIZE*/)
	{
		while (buf && buf[i] != '\n' && buf[i] != '\0')
			i ++;
		n ++;
	}
	if (buf[i] == '\n')
		line = ft_strncpy(buf, start, i);
	else
		line = ft_strncpy(buf, start, i-1);

	start = i + 1;
	i = i + 1;
	n ++;
	count ++;
	
	return (line);

	
}
 


