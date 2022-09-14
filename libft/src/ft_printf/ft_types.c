/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_types.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngonzale <ngonzale@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/17 18:40:44 by ngonzale          #+#    #+#             */
/*   Updated: 2022/05/18 04:06:05 by ngonzale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include "libft.h"

char	ft_find_type(char c)
{
	char	*type;

	type = ft_strchr("cspdiuxX%", c);
	if (type)
		return (*type);
	return (0);
}

char	*ft_s_type(char *str)
{
	char	*s;

	if (str)
		s = ft_strdup(str);
	else
		s = ft_strdup("(null)");
	return (s);
}

char	*ft_switch_types(char type, va_list ap)
{
	if (type == 's')
		return (ft_s_type(va_arg(ap, char *)));
	if (type == 'd' || type == 'i')
		return (ft_itoa(va_arg(ap, int)));
	if (type == 'u')
		return (ft_uitoa(va_arg(ap, unsigned int)));
	if (type == 'x')
		return (ft_uitoa_base(va_arg(ap, unsigned int), "0123456789abcdef"));
	if (type == 'X')
		return (ft_uitoa_base(va_arg(ap, unsigned int), "0123456789ABCDEF"));
	if (type == 'p')
		return (ft_ulltoa_base(va_arg(ap, unsigned long long),
				"0123456789abcdef"));
	if (type == '%')
		return (ft_strdup("%"));
	if (type == 'c')
		return (ft_c_to_str((char) va_arg(ap, int)));
	return (0);
}
