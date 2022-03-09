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
	int		i;
	int		lens1;
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
