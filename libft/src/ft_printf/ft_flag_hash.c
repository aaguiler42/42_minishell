/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_flag_hash.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngonzale <ngonzale@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/18 01:40:25 by ngonzale          #+#    #+#             */
/*   Updated: 2022/05/18 03:58:33 by ngonzale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

char	*ft_flag_hash(char *str, char type)
{
	char	*s;

	if (type == 'x' || type == 'p')
		s = ft_strjoin("0x", str);
	else
		s = ft_strjoin("0X", str);
	free (str);
	return (s);
}
