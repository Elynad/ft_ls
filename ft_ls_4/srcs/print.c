/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mameyer <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/24 19:25:06 by mameyer           #+#    #+#             */
/*   Updated: 2017/04/24 19:40:33 by mameyer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_ls.h"

void		my_printf(char **str, t_flags flags)
{
	if (flags.f_l == 0 && flags.f_t == 0)
		print_1(str, flags);
}

void		print_1(char **str, t_flags flags)
{
	int		i;
	int		j;

	i = 0;
	while (flags.f_a != 1 && str[i] && str[i][0] == '.')
		i++;
	if (flags.f_r == 1)
	{
		while (str[j])
			j++;
		while (j > i)
		{
			ft_putstr(str[j]);
			j--;
		}
	}
	else
	{
		while (str[i])
		{
			ft_putstr(str[i]);
			if (str[i + 1])
				ft_putchar('\t');
			i++;
		}
	}
}
