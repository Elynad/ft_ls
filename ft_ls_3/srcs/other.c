/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   other.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mameyer <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/19 13:40:44 by mameyer           #+#    #+#             */
/*   Updated: 2017/04/19 17:25:24 by mameyer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_ls.h"

int			find_index(t_flags flags)
{
	int		index;

	index = 0;
	if (flags.f_a == 1)
		index = 2;
	return (index);
}

char		*clear_str(char *str)
{
	int		i;

	if (str)
	{
		i = 0;
		while (str[i])
		{
			str[i] = '\0';
			i++;
		}
	}
	return (str);
}
