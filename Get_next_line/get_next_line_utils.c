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

char	*ft_strncpy(char *src, int index, int end)
{
	int	i;
	char	*dest;

	if (src == NULL)
		return (NULL);

	dest = malloc(sizeof(char) * (end - index + 1));
	if (dest == NULL)
		return (NULL);
	i = 0;
	while (index <= end && src[index] != '\0' && i < BUFFER_SIZE)
	{
		dest[i] = src[index];
		i++;
		index ++;
	}
	dest[i] = '\0';
	return (dest);
}

