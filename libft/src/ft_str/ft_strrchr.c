/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngonzale <ngonzale@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/19 19:04:59 by ngonzale          #+#    #+#             */
/*   Updated: 2022/04/20 19:11:10 by ngonzale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strrchr(const char *s, int c)
{
	char	*p;
	char	*res;

	res = 0;
	p = (char *) s;
	while (*p)
	{
		if (*p == (char) c)
			res = p;
		p++;
	}
	if (!c)
		return (p);
	return (res);
}
