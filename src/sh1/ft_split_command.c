/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split_command.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bfrimin <bfrimin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/16 10:50:02 by bfrimin           #+#    #+#             */
/*   Updated: 2015/03/16 11:58:00 by bfrimin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_minishell1.h"

static int		clean_command(char *command)
{
	int			i;
	int			count;

	i = 0;
	count = 0;
	while (command[i])
	{
		if (command[i] != ' ' && (command[i] != '	') && \
			(command[i + 1] == ' ' || command[i + 1] == '	' || \
			command[i + 1] == '\0'))
			count++;
		i++;
	}
	return (count);
}

char			**ft_split_command(char *command)
{
	char		**array;
	int			i;
	int			j;
	int			nb_words;

	nb_words = clean_command(command);
	j = 0;
	i = 0;
	array = (char **)malloc(sizeof(char *) * (nb_words + 1));
	while (*command && j < nb_words)
	{
		while (*command && (*command == ' ' || *command == '	'))
			command++;
		i = 0;
		while (command[i] != 0 && command[i] != ' ' && command[i] != '	')
			i++;
		array[j] = ft_strsub(command, 0, i);
		command += i;
		j++;
	}
	array[j] = NULL;
	return (array);
}
