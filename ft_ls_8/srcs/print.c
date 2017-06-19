/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mameyer <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/13 11:46:13 by mameyer           #+#    #+#             */
/*   Updated: 2017/06/19 15:44:28 by mameyer          ###   ########.fr       */
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
	t_print			print_infos;

	if (list->name && list->path)
	{
		if (flags.f_t == 1)
		{
			// sort by time
		}
		if (flags.f_r == 1)
		{
//			sort_reverse(list);
			// sort reverse
		}
		if (list->path && flags.f_l == 1)
		{
			init_print_struct(&print_infos);
			rec_high(list, &(print_infos.highest_dep));
			rec_longer_author_name(list, &(print_infos.longer_author_name));
			rec_longer_group_name(list, &(print_infos.longer_group_name));
			rec_highest_size(list, &(print_infos.highest_size));
			get_today_date(&(print_infos.today_date));
			print_l_flag(list, flags, print_infos);
		}
		else if (list->path)
			print_test(list);
	}
}

void		print_l_flag(t_lst *list, t_flags flags, t_print infos)
{
	struct stat			sb;

	if (stat(list->path, &sb) == -1 && lstat(list->path, &sb) == -1)
		perror(list->path);
	else
	{
		print_type(list->path);
		print_rights(list->path);
		print_dependencies(list, &infos);
		print_author(sb, &infos);
		print_group(sb, &infos);
		print_size(sb, &infos);
		print_time(sb, &infos);
		ft_putchar(' ');
		ft_putstr(list->name);
		ft_putchar('\n');
	}
	if (list->next)
		print_l_flag(list->next, flags, infos);
}
