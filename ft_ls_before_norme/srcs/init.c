/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mameyer <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/13 11:13:42 by mameyer           #+#    #+#             */
/*   Updated: 2017/06/16 14:53:31 by mameyer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_ls.h"

void		init_flags_struct(t_flags *flags)
{
	flags->f_l = 0;
	flags->f_a = 0;
	flags->f_R = 0;
	flags->f_r = 0;
	flags->f_t = 0;
}

void		init_fold_struct(t_fold *fold)
{
	fold->rep = NULL;
	fold->readfile = NULL;
}

void		init_print_struct(t_print *print)
{
	print->highest_dep = 0;
	print->longer_author_name = 0;
	print->longer_group_name = 0;
	print->highest_size = 0;
}
