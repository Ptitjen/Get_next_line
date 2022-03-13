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

size_t	ft_strlen(char *str)
{
	size_t	i;

	i = 0;
	if (str == NULL)
		return (0);
	while (str[i] != '\0')
		i ++;
	return (i);
}

char	*ft_copy_temp(char *str)
{
	size_t	j;
	size_t	i;
	char	*end;

	i = 0;
	j = 0;
	if (str == NULL)
		return (NULL);
	while (str[i] != '\n' && str[i] != '\0')
		i ++;
	if (i == ft_strlen(str))
	{
		free(str);
		return (NULL);
	}
	i ++;
	end = malloc(sizeof(char) * (ft_strlen(str) - i + 1));
	if (end == NULL)
		return (NULL);
	while (str[i] != '\0')
		end[j++] = str[i++];
	end[j] = '\0';
	free(str);
	return (end);
}

char	*ft_fill_line(char *tmp)
{
	int		i;
	char	*line;

	i = 0;
	if (tmp == NULL)
		return (NULL);
	while (tmp[i] != '\n' && tmp[i] != '\0')
		i ++;
	if (tmp[0] == '\0')
		return (NULL);
	line = malloc(sizeof(char) * (i + 2));
	if (line == NULL)
		return (NULL);
	i = 0;
	while (tmp[i] != '\n' && tmp[i] != '\0')
	{
		line[i] = tmp[i];
		i ++;
	}
	if (tmp[i] == '\n')
		line[i++] = '\n';
	line[i] = '\0';
	return (line);
}

char	*ft_strcat(char *dest, char *s1, char *s2)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	while (s1[i] != '\0')
	{
		dest[i] = s1[i];
		i ++;
	}
	if (s2 != NULL)
	{
		while (s2[j] != '\0')
		{
			dest[i] = s2[j];
			i ++;
			j ++;
		}
	}
	dest[i] = '\0';
	return (dest);
}

char	*ft_strjoin(char *s1, char *s2)
{
	char	*dest;

	dest = malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if ((dest == NULL || s1 == NULL) && s2 != NULL)
		return (NULL);
	dest = ft_strcat(dest, s1, s2);
	if (dest[0] == '\0')
	{
		free (dest);
		return (NULL);
	}
	return (dest);
}
