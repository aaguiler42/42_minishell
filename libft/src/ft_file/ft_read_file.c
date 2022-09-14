/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_read_file.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngonzale <ngonzale@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/08 20:01:47 by ngonzale          #+#    #+#             */
/*   Updated: 2022/06/14 13:33:20 by ngonzale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <fcntl.h>
#include <stdlib.h>
#include <unistd.h>

char	*ft_read_file(char *filename)
{
	int		fd;
	char	*s;
	char	*aux;
	char	*line;

	fd = open(filename, O_RDONLY);
	if (fd == -1)
		return (NULL);
	s = ft_calloc(1, sizeof(char));
	line = get_next_line(fd);
	while (s && line)
	{
		aux = s;
		s = ft_strjoin(s, line);
		free(aux);
		free(line);
		if (s)
			line = get_next_line(fd);
	}
	close(fd);
	return (s);
}
