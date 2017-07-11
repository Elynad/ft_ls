/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mameyer <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/11 15:37:23 by mameyer           #+#    #+#             */
/*   Updated: 2017/07/11 15:56:11 by mameyer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_ls.h"

void		print_fmaj(struct stat sb, t_flags flags)
{
	if (flags.f_fmaj == 1)
	{
		if (S_ISLNK(sb.st_mode))
			ft_putchar('@');
		else if (S_IEXEC & sb.st_mode && !(S_ISDIR(sb.st_mode)))
			ft_putchar('*');
		else if (S_IFIFO & sb.st_mode)
			ft_putchar('|');
	}
	if ((flags.f_fmaj == 1 || flags.f_p == 1) && S_ISDIR(sb.st_mode))
		ft_putchar('/');
}

void		sub_get_flags(char c, t_flags *flags)
{
	if (c == 'l')
		flags->f_l = 1;
	else if (c == 'r')
		flags->f_r = 1;
	else if (c == 'R')
		flags->f_rec = 1;
	else if (c == 't')
		flags->f_t = 1;
	else if (c == 'f')
		flags->f_f = 1;
	else if (c == 'F')
		flags->f_fmaj = 1;
	else if (c == 'g')
		flags->f_g = 1;
	else if (c == 'p')
		flags->f_p = 1;
}
