/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_trim.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaguiler <aaguiler@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/14 19:17:53 by aaguiler          #+#    #+#             */
/*   Updated: 2022/09/14 19:27:46 by aaguiler         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include "libft.h"

char	*ft_strtrim_spaces(char *s)
{
	//Free in trim
	s = ft_strtrim(s, " ");
	if (s)
		s = ft_strtrim(s, "\t");
	if (s)
		s = ft_strtrim(s, "\n");
	if (s)
		s = ft_strtrim(s, "\v");
	if (s)
		s = ft_strtrim(s, "\f");
	if (s)
		s = ft_strtrim(s, "\r");
	return(s);
}
