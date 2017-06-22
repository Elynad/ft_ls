/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   other_2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mameyer <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/21 12:16:58 by mameyer           #+#    #+#             */
/*   Updated: 2017/06/22 15:12:00 by mameyer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_ls.h"

void		sub_print_time(char *str)
{
	int		i;

	i = 20;
	ft_putchar(' ');
	while (i < 24)
	{
		ft_putchar(str[i]);
		i++;
	}
}

void		sub_open_dir(t_fold *fold, t_lst *list, t_flags flags, char *path)
{
	int		i;

	while ((fold->readfile = readdir(fold->rep)) != NULL)
	{
		if ((fold->readfile->d_name[0] != '.' && flags.f_a == 0)
				|| flags.f_a == 1)
		{
			if (i == 0)
				first(list, fold->readfile->d_name, path, &i);
			else
				next_conditions(list, fold->readfile->d_name, path, flags);
		}
	}
}
