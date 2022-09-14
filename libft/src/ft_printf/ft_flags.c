/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_flags.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngonzale <ngonzale@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/17 18:24:43 by ngonzale          #+#    #+#             */
/*   Updated: 2022/05/18 04:12:17 by ngonzale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"
#include "ft_printf_utils.h"

char	*ft_flags_shorts(char *s, struct s_flags flags, int spaces_len)
{
	if (s && (s[spaces_len] == '-' || flags.plus || flags.space))
	{
		s[0] = s[spaces_len];
		s[spaces_len] = '0';
	}
	if (s && flags.hash)
	{
		s[1] = s[spaces_len + 1];
		s[spaces_len + 1] = '0';
	}
	return (s);
}

char	*ft_flag_width(char *str, t_flags flags)
{
	char	*s;
	char	*spaces;
	int		spaces_len;

	spaces_len = flags.width - ft_strlen(str);
	if (spaces_len <= 0)
		return (str);
	spaces = ft_calloc(spaces_len + 1, sizeof(char));
	if (!spaces)
		return (0);
	if (flags.zero && !flags.minus)
		ft_memset(spaces, '0', spaces_len);
	else
		ft_memset(spaces, ' ', spaces_len);
	if (flags.minus)
		s = ft_strjoin(str, spaces);
	else
	{
		s = ft_strjoin(spaces, str);
		if (s && flags.zero)
			s = ft_flags_shorts(s, flags, spaces_len);
	}
	free(str);
	free(spaces);
	return (s);
}

char	*ft_flag_precision(char *str, char type, int precision)
{
	char	*s;
	t_flags	flags;

	if (precision == 0)
	{
		free(str);
		return (ft_strdup(""));
	}
	if (precision == -1)
		return (str);
	if (type == 's')
	{
		s = ft_substr(str, 0, precision);
		free(str);
		return (s);
	}
	flags = (t_flags){.width = precision, .zero = 1};
	if (*str == '-')
		flags.width++;
	s = ft_flag_width(str, flags);
	return (s);
}
