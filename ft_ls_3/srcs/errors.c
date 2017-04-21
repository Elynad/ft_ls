/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mameyer <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/18 12:22:15 by mameyer           #+#    #+#             */
/*   Updated: 2017/04/21 11:34:33 by mameyer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_ls.h"

void		error(int a)
{
	if (a == 0)
		ft_putstr("Dynamic allocation failed.\n");
	else if (a == 1)
		ft_putstr("Stat function failed.\n");
	else if (a == 2)
		ft_putstr("Closing failed.\n");
	exit(1);
}

void		unknown_flags(char flag)
{
	ft_putstr("ft_ls: illegal option -- ");
	ft_putchar(flag);
	ft_putchar('\n');
	ft_putstr("usage: ft_ls [-lRart] [file ...]\n");
	error(9);
}

void		no_fildir(char *fildir)
{
	ft_putstr("ft_ls: ");
	ft_putstr(fildir);
	ft_putstr(": No such file or directory\n");
	ft_putchar('a');
}
