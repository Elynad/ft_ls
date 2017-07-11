/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mameyer <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/13 10:53:45 by mameyer           #+#    #+#             */
/*   Updated: 2017/07/11 17:42:03 by mameyer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_ls.h"

int			main(int argc, char **argv)
{
	t_flags			flags;
	t_lst			*fargs;

	(void)argc;
	init_flags_struct(&flags);
	fargs = parsing(argv, &flags);
	if (!(fargs->next) && flags.f_rec == 0)
		flags.one = 1;
	submain(fargs, flags);
	if (fargs)
		free(fargs);
	return (0);
}

void		submain(t_lst *fargs, t_flags flags)
{
	core(fargs->name, flags);
	if (fargs->next)
	{
		ft_putchar('\n');
		submain(fargs->next, flags);
	}
}
