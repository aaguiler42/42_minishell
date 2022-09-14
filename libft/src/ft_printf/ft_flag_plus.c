/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_flag_plus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngonzale <ngonzale@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/18 01:42:33 by ngonzale          #+#    #+#             */
/*   Updated: 2022/05/18 03:58:47 by ngonzale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

char	*ft_flag_plus(char *str)
{
	char	*s;

	if (*str == '-')
		return (str);
	s = ft_strjoin("+", str);
	free(str);
	return (s);
}
