/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mameyer <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/20 14:14:15 by mameyer           #+#    #+#             */
/*   Updated: 2017/05/20 17:14:40 by mameyer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_ls.h"

void	print_test(t_lst *fargs)
{
	ft_putstr(fargs->name);
	ft_putchar('\n');
	if (fargs->next)
		print_test(fargs->next);
}

void	print_flags_test(t_flags flags)
{
	ft_putnbr(flags.f_l);
	ft_putnbr(flags.f_R);
	ft_putnbr(flags.f_a);
	ft_putnbr(flags.f_r);
	ft_putnbr(flags.f_t);
}

int		main(int argc, char **argv)
{
	t_flags		flags;
	t_lst		*fargs;

	init_flags_struct(&flags);
//	init_fargs_struct(fargs);
	fargs = parsing(argv, &flags, fargs);
	submain(fargs, flags);
	return (0);
}

void	submain(t_lst *fargs, t_flags flags)
{
	if (fargs->next)
		core_func(fargs->name, flags, 0);		// Il y a d'autres elems
	else
		core_func(fargs->name, flags, 1);		// C'est le dernier elem
	if (fargs->next)
		submain(fargs->next, flags);
}
