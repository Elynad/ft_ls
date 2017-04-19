/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mameyer <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/18 11:28:32 by mameyer           #+#    #+#             */
/*   Updated: 2017/04/19 17:48:24 by mameyer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_ls.h"

int		main(int argc, char **argv)
{
	t_flags			flags;
	char			**fargs;

	init_flags_struct(&flags);
	fargs = parsing(argv, &flags);
	recursive_func(fargs[0], 0, flags);

	// Need to make a function that frees every single allocated stuff
	return (0);
}
