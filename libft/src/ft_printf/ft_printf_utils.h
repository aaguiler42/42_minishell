/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngonzale <ngonzale@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/18 04:10:48 by ngonzale          #+#    #+#             */
/*   Updated: 2022/05/18 04:17:27 by ngonzale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_UTILS_H
# define FT_PRINTF_UTILS_H

# include <stdarg.h>

typedef struct s_flags {
	int	plus;
	int	space;
	int	hash;
	int	dot;
	int	precision;
	int	minus;
	int	zero;
	int	width;
}			t_flags;

char	*ft_flag_plus(char *str);
char	*ft_flag_space(char *str);
char	*ft_flag_hash(char *str, char type);
char	*ft_flag_width(char *str, t_flags flags);
char	*ft_flag_precision(char *str, char type, int precision);
char	ft_find_type(char c);
char	*ft_switch_types(char type, va_list ap);

#endif
