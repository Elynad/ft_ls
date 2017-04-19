/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mameyer <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/18 12:22:15 by mameyer           #+#    #+#             */
/*   Updated: 2017/04/19 11:39:59 by mameyer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_ls.h"

void		error(int a)
{
	if (a == 0)
		ft_putstr("Dynamic allocation failed.\n");
	else if (a == 1)
		ft_putstr("Stat function failed.\n");
	exit(0);
}
