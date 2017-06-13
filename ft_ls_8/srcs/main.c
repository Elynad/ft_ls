/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mameyer <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/13 10:53:45 by mameyer           #+#    #+#             */
/*   Updated: 2017/06/13 17:07:13 by mameyer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_ls.h"

int			main(int argc, char **argv)
{
	t_flags			flags;
	t_lst			*fargs;

	init_flags_struct(&flags);
	ft_putchar('A');
	fargs = parsing(argv, &flags);
	ft_putchar('B');
	submain(fargs, flags);
	ft_putchar('C');
	return (0);
}

void		submain(t_lst *fargs, t_flags flags)
{
	ft_putchar('1');
	core(fargs->name, flags);
	ft_putchar('2');
	if (fargs->next)
	{
		ft_putchar('\n');
		submain(fargs->next, flags);
	}
}
