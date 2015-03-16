/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_error.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bfrimin <bfrimin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/16 16:20:15 by bfrimin           #+#    #+#             */
/*   Updated: 2015/03/16 16:32:29 by bfrimin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_minishell1.h>

void		display_error(char **args)
{
	ft_putstr("cd:");
	ft_putstr(args[1]);
	ft_putstr(": No such file or directory\n");
}
