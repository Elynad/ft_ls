/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mameyer <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/24 13:34:25 by mameyer           #+#    #+#             */
/*   Updated: 2017/04/24 19:50:30 by mameyer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_ls.h"

void	error(int a, char *str)
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
		ft_putstr("Dynamic allocation failed somewhere.\n");
		exit (1);
	}
	else if (a == 3)
	{
		ft_putstr("Closing function failed.\n");
		exit(1);
	}
	else if (a == 4)
	{
		ft_putstr("Opening function failed.\n");
		exit(1);
	}
	else if (a == 5)
	{
		ft_putstr("Stat function failed.\n");
		exit(1);
	}
}
