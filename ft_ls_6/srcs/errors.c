/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mameyer <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/20 14:54:04 by mameyer           #+#    #+#             */
/*   Updated: 2017/05/20 17:57:04 by mameyer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_ls.h"

void		error_1(int a, char *str)
{
	if (a == 0)
	{
		ft_putstr("ft_ls: ");
		ft_putstr(str);
		ft_putstr(": No such file or directory\n");
	}
	else if (a == 1)
	{
		ft_putstr("ft_ls: illegal option -- ");
		ft_putstr(str);
		ft_putstr("\nusage: ./ft_ls [-lRart] [file ...]\n");
		exit(1);
	}
	else if (a == 2)
	{
		ft_putstr("Malloc failed - ");
		ft_putstr(str);
		exit(1);
	}
	else if (a == 3)
	{
		ft_putstr("ft_ls: ");
		ft_putstr(str);
		ft_putstr(": No such file or directory\n");
	}
	else
		error_2(a, str);
}

void		error_2(int a, char *str)
{
	if (a == 4)
	{
		ft_putstr("Opening failed - ");
		ft_putstr(str);
		exit(1);
	}
	else if (a == 5)
	{
		ft_putstr("Closing failed - ");
		ft_putstr(str);
		exit(1);
	}
}
