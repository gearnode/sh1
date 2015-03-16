/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstprintf_del.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bfrimin <bfrimin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/04 13:31:07 by bfrimin           #+#    #+#             */
/*   Updated: 2015/03/04 17:35:18 by bfrimin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void ft_lstprintf_del(t_printfunc **alst)
{
	t_printfunc *printfunction;
	t_printfunc *next;

	printfunction = *alst;
	while (printfunction)
	{
		next = printfunction->next;
		free(printfunction);
		printfunction = next;
	}
	*alst = NULL;
}
