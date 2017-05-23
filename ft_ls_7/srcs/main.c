/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mameyer <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/23 14:54:55 by mameyer           #+#    #+#             */
/*   Updated: 2017/05/23 16:37:23 by mameyer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_ls.h"

void		print_test(t_lst *fargs)
{
	ft_putstr("Name = ");
	ft_putstr(fargs->name);
	ft_putstr("\tPath = ");
	ft_putstr(fargs->path);
	ft_putchar('\n');
	if (fargs->next)
		print_test(fargs->next);
}


int			main(int argc, char **argv)
{
	t_lst		*fargs;
	t_flags		flags;

	fargs = parsing(argv, &flags);
	print_test(fargs);
	// Trier fargs
	rec_main(fargs, flags);
	return (0);
}

void		rec_main(t_lst *content, t_flags flags)
{
	core_func(content->path, flags);
	if (content->next)
		rec_main(content->next, flags);
}
