/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mameyer <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/13 11:46:13 by mameyer           #+#    #+#             */
/*   Updated: 2017/06/13 13:43:12 by mameyer          ###   ########.fr       */
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
