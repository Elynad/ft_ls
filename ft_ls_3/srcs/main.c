/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mameyer <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/18 11:28:32 by mameyer           #+#    #+#             */
/*   Updated: 2017/04/19 15:40:36 by mameyer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_ls.h"

int		main(int argc, char **argv)
{
	t_flags			flags;
	char			**fargs;

	init_flags_struct(&flags);
	fargs = parsing(argv, &flags);
	if (!fargs[1])
		fargs = open_directory(fargs[0], flags);
	if (flags.f_R == 1)
		recursive_func(fargs[0], 0, flags);
	else
		simply_dir(fargs, flags);
	ft_putchar('z');
	// Need to make a function that frees every single allocated stuff
	return (0);
}
