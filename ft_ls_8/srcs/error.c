/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mameyer <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/13 11:29:49 by mameyer           #+#    #+#             */
/*   Updated: 2017/06/14 10:51:01 by mameyer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_ls.h"

void		error(int a, char *str)
{
	if (a == 0)
	{			// PROVISOIRE
		ft_putstr("\n/////////////////////////////////////////////////////\n");
		ft_putstr("Malloc failed - ");
		ft_putstr(str);
		ft_putstr("\n/////////////////////////////////////////////////////\n");
		exit(-1);
	}
	if (a == 1)
	{
		ft_putstr("ft_ls: ");
		ft_putstr(str);
		ft_putstr(": No such file or directory\n");
	}
	if (a == 2)
	{
		ft_putstr("Opening failed - ");
		ft_putstr(str);
		exit(-1);
	}
	if (a == 3)
	{
		ft_putstr("Closing failed - ");
		ft_putstr(str);
		exit(-1);
	}
	if (a == 4)
	{
		ft_putstr("Stat func failed - ");
		ft_putstr(str);
		ft_putstr("\n\n");
		printf("%s\n", strerror(errno));
		exit(-1);
	}
}
