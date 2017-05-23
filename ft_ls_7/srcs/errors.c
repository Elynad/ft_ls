/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mameyer <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/23 15:10:55 by mameyer           #+#    #+#             */
/*   Updated: 2017/05/23 16:26:24 by mameyer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_ls.h"

void		error(int a, char *str)
{
	if (a == 0)
	{
		ft_putstr("ft_ls: illegal option -- ");
		ft_putstr(str);
		ft_putstr("\nusage: ft_ls: [-lRart] [file ...]\n");
		exit (1);
	}
	if (a == 1)
	{
		ft_putstr("Dynamic allocation failed - ");
		ft_putstr(str);
		ft_putchar('\n');
		exit (1);
	}
	if (a == 2)
	{
		ft_putstr("ft_ls: ");
		ft_putstr(str);
		ft_putstr(": No such file or directory\n");
	}
	if (a == 3)
	{
		ft_putstr("Opening failed - ");
		ft_putstr(str);
		ft_putchar('\n');
		exit (1);
	}
	if (a == 4)
	{
		ft_putstr("Closing failed - ");
		ft_putstr(str);
		ft_putchar('\n');
		exit (1);
	}
}
