/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstprintfnew.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bfrimin <bfrimin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/04 13:31:07 by bfrimin           #+#    #+#             */
/*   Updated: 2015/03/04 17:35:21 by bfrimin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_printfunc			*ft_lstprintfnew(char arg,
					long long (*print_ptr)(va_list ap, t_fmt *arg_fmt))
{
	t_printfunc *new_list;

	new_list = (t_printfunc *)malloc(sizeof(t_printfunc));
	if (!new_list)
		return (NULL);
	new_list->specifier = arg;
	new_list->function_ptr = print_ptr;
	new_list->next = (t_printfunc *)NULL;
	return (new_list);
}

static t_printfunc	*ft_lstprintffull_char_string(t_printfunc *printfunction)
{
	printfunction->next = ft_lstprintfnew('C', &(ft_print_wchar));
	printfunction = printfunction->next;
	printfunction->next = ft_lstprintfnew('c', &(ft_print_char));
	printfunction = printfunction->next;
	printfunction->next = ft_lstprintfnew('S', &(ft_print_strwchar));
	printfunction = printfunction->next;
	printfunction->next = ft_lstprintfnew('s', &(ft_print_string));
	printfunction = printfunction->next;
	return (printfunction);
}

static t_printfunc	*ft_lstprintffull_other(t_printfunc *printfunction)
{
	printfunction->next = ft_lstprintfnew('o', &(ft_print_oct));
	printfunction = printfunction->next;
	printfunction->next = ft_lstprintfnew('O', &(ft_print_oct));
	printfunction = printfunction->next;
	printfunction->next = ft_lstprintfnew('x', &(ft_print_hexa));
	printfunction = printfunction->next;
	printfunction->next = ft_lstprintfnew('X', &(ft_print_hexa));
	printfunction = printfunction->next;
	printfunction->next = ft_lstprintfnew('p', &(ft_print_hexa));
	printfunction = printfunction->next;
	printfunction->next = ft_lstprintfnew('u', &(ft_print_dec));
	printfunction = printfunction->next;
	printfunction->next = ft_lstprintfnew('U', &(ft_print_dec));
	printfunction = printfunction->next;
	printfunction->next = ft_lstprintfnew('b', &(ft_print_bin));
	printfunction = printfunction->next;
	printfunction->next = ft_lstprintfnew('f', &(ft_print_float));
	printfunction = printfunction->next;
	printfunction->next = ft_lstprintfnew('F', &(ft_print_float));
	printfunction = printfunction->next;
	return (printfunction);
}

t_printfunc			*ft_lstprintffull(void)
{
	t_printfunc	*printfunction;
	t_printfunc	*printfunction_first;

	printfunction = ft_lstprintfnew('i', &(ft_print_int_signed));
	printfunction->next = ft_lstprintfnew('d', &(ft_print_int_signed));
	printfunction_first = printfunction;
	printfunction = printfunction->next;
	printfunction->next = ft_lstprintfnew('D', &(ft_print_long_signed));
	printfunction = printfunction->next;
	printfunction = ft_lstprintffull_char_string(printfunction);
	printfunction = ft_lstprintffull_other(printfunction);
	return (printfunction_first);
}
