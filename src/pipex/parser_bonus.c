/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngonzale <ngonzale@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/26 19:43:27 by ngonzale          #+#    #+#             */
/*   Updated: 2023/01/02 23:36:48 by ngonzale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

void	ft_count_args(char *command, size_t *argc)
{
	char	*ptr;
	char	searching;

	*argc = 1;
	ptr = command;
	searching = 0;
	while (*ptr)
	{
		if (*ptr == searching)
			searching = 0;
		if (!searching && ft_strchr("\"'", *ptr))
		{
			searching = *ptr;
			if (*argc == 1)
				*ptr = '\\';
		}
		if (!searching && *ptr == ' ')
		{
			*ptr = 0;
			if (*(ptr + 1) != ' ')
				*argc += 1;
		}
		ptr++;
	}
}

void	ft_join_strs(char **string, char **aux, size_t i)
{
	char	*string_aux;

	*string = ft_strdup("");
	if (!*string)
	{
		while (aux[i])
			free(aux[i++]);
		free(aux);
		return ;
	}
	i = 0;
	while (aux[i])
	{
		if (*string)
		{
			string_aux = *string;
			*string = ft_strjoin(*string, aux[i]);
			free(string_aux);
		}
		free(aux[i]);
		i++;
	}
	free(aux);
}

void	ft_manipulate_arg(char **string)
{
	char	*string_aux;
	char	*s;
	char	**aux;

	if (*string[0] == '\'' || *string[0] == '\"')
	{
		s = ft_calloc(2, sizeof(char));
		if (!s)
		{
			free(string);
			string = NULL;
			return ;
		}
		s[0] = *string[0];
		string_aux = *string;
		*string = ft_strtrim(*string, s);
		free(string_aux);
		free(s);
		if (!*string)
			return ;
	}
	aux = ft_split(*string, '\\');
	free(*string);
	if (aux)
		ft_join_strs(string, aux, 0);
}

void	ft_separate_command(char ***strings, char *ptr,
		size_t argc, size_t i)
{
	size_t	j;

	while (++i < argc)
	{
		while (!*ptr)
			ptr++;
		(*strings)[i] = ft_strdup(ptr);
		if ((*strings)[i])
			ft_manipulate_arg(*strings + i);
		if (!(*strings)[i])
		{
			j = 0;
			while (j < i)
			{
				free((*strings)[j]);
				j++;
			}
			free(*strings);
			*strings = NULL;
		}
		while (*ptr)
			ptr++;
	}
}

char	**ft_parse_command(char *arg)
{
	char	*ptr;
	size_t	argc;
	char	**strings;
	char	*clean_command;

	clean_command = ft_strtrim(arg, " ");
	if (!clean_command)
		return (NULL);
	ft_count_args(clean_command, &argc);
	strings = ft_calloc(argc + 1, sizeof(char *));
	if (!strings)
	{
		free(clean_command);
		return (NULL);
	}
	ptr = clean_command;
	ft_separate_command(&strings, ptr, argc, -1);
	free(clean_command);
	return (strings);
}
