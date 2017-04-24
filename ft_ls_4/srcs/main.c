/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mameyer <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/24 13:24:56 by mameyer           #+#    #+#             */
/*   Updated: 2017/04/24 19:48:11 by mameyer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_ls.h"

int			main(int argc, char **argv)
{
	t_flags			flags;
	char			**fargs;
	char			**sorted;
	int				i;

	init_flags_struct(&flags);
	fargs = parsing(argv, &flags);
	// SORT FARGS
	i = 0;
	while (fargs[i])							// TEST
	{
		recursive_func(fargs[i], 0, flags);
		i++;
	}											// END TEST
//	sorted = sorting_fargs(fargs);
	return (0);
}
