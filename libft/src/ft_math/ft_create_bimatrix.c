/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_create_bimatrix.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngonzale <ngonzale@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/07 14:32:15 by ngonzale          #+#    #+#             */
/*   Updated: 2022/06/07 14:37:35 by ngonzale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	**ft_create_bimatrix(size_t height, size_t width)
{
	int		**matrix;
	size_t	i;

	matrix = (int **) ft_calloc(height, sizeof(int *));
	if (!matrix)
		return (NULL);
	i = 0;
	while (i < height)
	{
		matrix[i] = (int *) ft_calloc(width, sizeof(int));
		if (!matrix[i])
		{
			ft_free_bimatrix(matrix, i);
			return (NULL);
		}
		i++;
	}
	return (matrix);
}
