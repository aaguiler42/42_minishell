/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngonzale <ngonzale@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/07 11:53:23 by ngonzale          #+#    #+#             */
/*   Updated: 2022/06/07 11:56:16 by ngonzale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_UTILS_H
# define GET_NEXT_LINE_UTILS_H

size_t	ft_strlen_protected(const char *s);
char	*ft_substr_sizeprotected(char const *s, unsigned int start, size_t len);
char	*ft_strjoin_sizeprotected(char const *s1, char const *s2);

#endif
