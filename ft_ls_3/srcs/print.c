/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mameyer <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/18 16:16:43 by mameyer           #+#    #+#             */
/*   Updated: 2017/04/18 16:24:05 by mameyer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_ls.h"

void		my_printf(char **str, t_flags flags)
{
	if (flags.f_l == 0 && flags.f_t == 0)
		print_1(str, flags);
	else if (flags.f_l == 1)
		print_l_flag(str, flags);
}

void		print_1(char **str, t_flags flags)		// TEST - Need to be modified
{
	int		i = 0;
	while (str[i])
	{
		ft_putstr(str[i]);
		ft_putchar('\t');
		i++;
	}
}

void		print_l_flag(char **str, t_flags flags)	// TEST - Need to be modified
{
	int		i = 0;
	while (str[i])
	{
		ft_putstr(str[i]);
		ft_putchar('\n');
		i++;
	}
}
