/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mameyer <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/24 13:24:56 by mameyer           #+#    #+#             */
/*   Updated: 2017/04/26 16:03:30 by mameyer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_ls.h"

int			main(int argc, char **argv)
{
	t_flags			flags;
	char			**fargs;
	char			**sorted;
	int				i;
	int				j;

	init_flags_struct(&flags);
	fargs = parsing(argv, &flags);
	conditions(fargs, flags);
	return (0);
	ft_putchar('a');
	// SORT FARGS
	j = 0;
	while (fargs[j])
		j++;
	i = 0;
	while (fargs[i])							// TEST
	{
		if (j >= 2)
		{
			ft_putstr(fargs[i]);
			ft_putstr(":\n");
		}
		recursive_func(fargs[i], 0, flags);
		i++;
	}											// END TEST
//	sorted = sorting_fargs(fargs);
	return (0);
}
