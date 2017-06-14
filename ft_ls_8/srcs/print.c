/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mameyer <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/13 11:46:13 by mameyer           #+#    #+#             */
/*   Updated: 2017/06/14 17:09:58 by mameyer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_ls.h"

void		print_test(t_lst *list)			// PROVISOIRE
{
	ft_putstr(list->name);
	ft_putchar('\n');
	if (list->next)
		print_test(list->next);
}

void		my_printf(t_lst *list, t_flags flags)
{
	if (flags.f_l == 1)
		print_l_flag(list, flags);
}

void		print_l_flag(t_lst *list, t_flags flags)
{
	print_type(list->path);
	print_rights(list->path);
	ft_putchar('\t');
	ft_putstr(list->name);		// test
	ft_putchar('\n');
	if (list->next)
		print_l_flag(list->next, flags);
}
