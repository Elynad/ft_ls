/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mameyer <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/13 11:46:13 by mameyer           #+#    #+#             */
/*   Updated: 2017/07/08 22:00:01 by mameyer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_ls.h"

void		print_test(t_lst *list)
{
	ft_putstr(list->name);
	ft_putchar('\n');
	if (list->next)
		print_test(list->next);
}

void		my_printf(t_lst *list, t_flags flags, int one)
{
	t_print			print_infos;

	if (list->name && list->path)
	{
		if (list->path && flags.f_l == 1)
		{
			sub_print_l(&print_infos, list);
			if (one == 0)
			{
				ft_putstr("total ");
				ft_putnbr(get_total(list));
				ft_putchar('\n');
			}
			print_l_flag(list, flags, print_infos);
		}
		else if (list->path)
			print_test(list);
	}
}

void		sub_print_l(t_print *infos, t_lst *list)
{
	init_print_struct(infos);
	rec_high(list, &(infos->highest_dep));
	rec_longer_author_name(list, &(infos->longer_author_name));
	rec_longer_group_name(list, &(infos->longer_group_name));
	rec_highest_size(list, &(infos->highest_size));
	get_today_date(&(infos->today_date));
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
		if (S_ISLNK(sb.st_mode))
		{
			ft_putstr(" -> ");
		}
		ft_putchar('\n');
	}
	if (list->next)
		print_l_flag(list->next, flags, infos);
}
