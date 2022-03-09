/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeulliot <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/03 13:41:46 by jeulliot          #+#    #+#             */
/*   Updated: 2022/03/03 13:41:49 by jeulliot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# include<stdlib.h>
# include <sys/types.h>
# include <sys/uio.h>
# include <unistd.h>
# include<sys/stat.h>
# include<fcntl.h>


char	*get_next_line(int fd);
char	*ft_strncpy(char *src, int index, int end);
char	*ft_strcat(char *dest, char *src, int len);
int	ft_strlen(char *str);

#endif
