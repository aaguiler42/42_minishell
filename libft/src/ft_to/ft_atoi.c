/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngonzale <ngonzale@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/19 19:57:19 by ngonzale          #+#    #+#             */
/*   Updated: 2022/04/21 01:51:14 by ngonzale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

static int	ft_isspace(char c)
{
	if (c == '\t' || c == '\n' || c == '\v'
		|| c == '\f' || c == '\r' || c == ' ')
		return (1);
	return (0);
}

int	ft_atoi(const char *str)
{
	int	i;
	int	total;
	int	signo;

	i = 0;
	total = 0;
	signo = 1;
	while (str[i] && ft_isspace(str[i]))
		i++;
	if (str[i] == '-')
		signo = -1;
	if (str[i] == '+' || str[i] == '-')
		i++;
	while (str[i] && str[i] >= '0' && str[i] <= '9')
	{
		total *= 10;
		total += str[i] - '0';
		i++;
	}
	total *= signo;
	if (signo == 1 && total < 0)
		return (-1);
	if (signo == -1 && total > 0)
		return (0);
	return (total);
}
