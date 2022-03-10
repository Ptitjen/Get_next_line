/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeulliot <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/03 13:41:32 by jeulliot          #+#    #+#             */
/*   Updated: 2022/03/03 13:41:35 by jeulliot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"get_next_line.h"
#include<stdio.h>

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



char	*ft_copy_temp(char *str) // met a jour le buf temporaire en enlveant le debut jusque NL
{
	int	lenstr;
	int	i;
	int j;
	char	*end;

	lenstr = ft_strlen(str);
	
	i = 0;
	j = 0;

	while (str[i] != '\n' && i < lenstr)
		i ++;

	if (i != lenstr)
	{
		i ++;
		end = malloc(sizeof(char) * (lenstr - i + 1));
		while (str[i + j] != '\0')
		{
			end[j] = str[i + j];
			j ++;
		}
		end [j] = '\0';
	}
	else
		end = NULL;
	free(str);
	 // pas de \n dedans : tte le buf temp est dans line => charger nouveau buffer
	return (end);
	
}

char	*ft_fill_line(char *tmp) // copie jusque NL ou fin du buf -  OK
{
	int	i;
	int	j;
	char *line;
	
	i = 0;
	j = 0;
	if (tmp == NULL)
		return (NULL);
	//printf("tmp : %s", tmp);
	while (tmp[i] != '\n' && tmp[i] != '\0')
		i ++;
	line = malloc(sizeof(char) * (i + 1));
	//printf("line : %p", line);
	while (j <= i)
	{
		line[j] = tmp[j];
		j ++;
	}
	if (tmp[j - 1] == '\n')
		line[j] = '\0';

	return (line);
}

char	*ft_strjoin(char *s1, char *s2)
{
	size_t	i;
	size_t	lens1;
	size_t	tlen;
	char	*dest;

	i = 0;
	lens1 = ft_strlen(s1);
	tlen = lens1 + ft_strlen(s2) + 1;
	dest = malloc(sizeof(char) * tlen);
	//printf("dest : %p", dest);
	if ((dest == NULL || s1 == NULL) && s2 != NULL)
		return (NULL);
	while (i < lens1)
	{
		dest[i] = s1[i];
		i ++;
	}
	if (s2 != NULL)
		while (i < tlen - 1)
		{
			dest[i] = s2[i - lens1];
			i ++;
		}
	dest[i] = '\0';

	
	free(s1);
	free(s2);
	if (dest[0] == '\0')
	{
		free (dest);
		return (NULL);
	}
	return (dest);
}
