/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mameyer <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/20 14:16:47 by mameyer           #+#    #+#             */
/*   Updated: 2017/05/20 17:17:40 by mameyer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_ls.h"

void		init_flags_struct(t_flags *flags)
{
	if (!(flags = malloc(sizeof(t_flags))))
		error_1(2, "init.c - line 17");
	flags->f_l = 0;
	flags->f_R = 0;
	flags->f_a = 0;
	flags->f_r = 0;
	flags->f_t = 0;
}

void		init_fargs_struct(t_lst *fargs)
{
	if (!(fargs = malloc(sizeof(t_lst))))
		error_1(2, "init.c - line 26");
	fargs->next = NULL;
	fargs->name = NULL;
	fargs->path = NULL;
}

void		init_fold_struct(t_fold *fold)
{
	if (!(fold = malloc(sizeof(t_fold))))
		error_1(2, "init.c - line 38");
	fold->rep = NULL;
	fold->readfile = NULL;
}
