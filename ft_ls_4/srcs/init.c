/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mameyer <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/24 13:26:28 by mameyer           #+#    #+#             */
/*   Updated: 2017/04/24 15:17:09 by mameyer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_ls.h"

void		init_flags_struct(t_flags *flags)
{
	flags->f_l = 0;
	flags->f_R = 0;
	flags->f_a = 0;
	flags->f_r = 0;
	flags->f_t = 0;
}

void		init_fold_struct(t_fold *fold)
{
	fold->rep = NULL;
	fold->readfile = NULL;
	fold->index = 0;
}
