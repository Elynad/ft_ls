/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mameyer <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/13 10:53:45 by mameyer           #+#    #+#             */
/*   Updated: 2017/07/07 13:48:12 by mameyer          ###   ########.fr       */
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
	submain(fargs, flags);
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
