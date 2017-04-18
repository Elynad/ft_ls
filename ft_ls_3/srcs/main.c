/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mameyer <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/18 11:28:32 by mameyer           #+#    #+#             */
/*   Updated: 2017/04/18 15:59:42 by mameyer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_ls.h"

int		main(int argc, char **argv)
{
	t_flags			flags;
	char			**fargs;

	init_flags_struct(&flags);
	fargs = parsing(argv, &flags);

	if (flags.f_R == 1)
		recursive_func(fargs, 0, 0);
	else
		simply_dir(fargs, flags);


	// Need to make a function that frees every single allocated stuff
	return (0);
}
