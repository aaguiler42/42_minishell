/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngonzale <ngonzale@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/11 00:18:43 by ngonzale          #+#    #+#             */
/*   Updated: 2022/05/18 04:14:16 by ngonzale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"
#include "ft_printf_utils.h"

char	*ft_char_null(char *s, t_flags *flags, int *s_len, char type)
{
	if (!*s && type == 'c')
	{
		ft_putchar_fd(0, 1);
		free(s);
		if (!flags->width)
		{
			*s_len = -1;
			return (0);
		}
		*s_len = 1;
		flags->width--;
		s = ft_calloc(0, 0);
	}
	return (s);
}

char	ft_set_type_flags(char **str, t_flags *flags)
{
	while (**str)
	{
		if (**str == '+')
			flags->plus = 1;
		else if (**str == ' ')
			flags->space = 1;
		else if (**str == '#')
			flags->hash = 1;
		else if (**str == '.')
			flags->dot = 1;
		else if (**str == '-')
			flags->minus = 1;
		else if (**str == '0' && !ft_isdigit(*(*str - 1)) && !flags->dot)
			flags->zero = 1;
		else if (ft_isdigit(**str) && flags->dot)
				flags->precision = flags->precision * 10 + **str - '0';
		else if (ft_isdigit(**str) && !flags->dot)
				flags->width = flags->width * 10 + **str - '0';
		*(str) += 1;
		if (ft_find_type(*(*str - 1)))
			return (*(*str - 1));
	}
	return (0);
}

char	*ft_format(char *s, t_flags flags, char type)
{
	if (type == 'p')
		flags.hash = 1;
	if ((type == 'x' || type == 'X') && s[0] == '0')
		flags.hash = 0;
	if (s && flags.dot)
	{
		if (type != 's' && flags.precision == 0 && s[0] != '0')
			flags.precision = -1;
		s = ft_flag_precision(s, type, flags.precision);
		flags.zero = 0;
	}
	if (s && flags.plus)
		s = ft_flag_plus(s);
	else if (s && flags.space && type != 's')
		s = ft_flag_space(s);
	if (s && flags.hash)
		s = ft_flag_hash(s, type);
	if (s && flags.width)
		s = ft_flag_width(s, flags);
	return (s);
}

int	ft_print_param(char **str, va_list ap)
{
	char	*s;
	char	type;
	t_flags	flags;
	int		s_len;

	flags = (t_flags){0};
	s_len = 0;
	type = ft_set_type_flags(str, &flags);
	if (!type)
		return (0);
	s = ft_switch_types(type, ap);
	if (!s)
		return (0);
	s = ft_char_null(s, &flags, &s_len, type);
	if (s_len == -1)
		return (1);
	s = ft_format(s, flags, type);
	if (!s)
		return (0);
	ft_putstr_fd(s, 1);
	s_len += ft_strlen(s);
	free(s);
	return (s_len);
}

int	ft_printf(const char *str, ...)
{
	char	*s;
	va_list	ap;
	size_t	n;

	va_start(ap, str);
	s = (char *) str;
	n = 0;
	while (*s)
	{
		if (*s == '%')
		{
			s++;
			n += ft_print_param(&s, ap);
		}
		else
		{
			ft_putchar_fd(*s, 1);
			s++;
			n++;
		}
	}
	va_end(ap);
	return (n);
}
