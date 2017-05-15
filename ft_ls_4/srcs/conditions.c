/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conditions.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mameyer <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/26 15:55:26 by mameyer           #+#    #+#             */
/*   Updated: 2017/04/26 16:07:36 by mameyer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_ls.h"

void		conditions(char **fargs, t_flags flags)
{
	struct stat			sb;
	int					i;

	i = 0;
	if (!fargs)
		recursive_func("./", 0, flags);
	else
	{
		while (fargs[i])
		{
			if (stat(fargs[i], &sb) == -1)
				error(0, fargs[i]);
			if (S_ISDIR(sb.st_mode))
			{
				if (fargs[i + 1] || fargs[i - 1])
				{
					ft_putstr(fargs[i]);
					ft_putstr(":\n");
				}
				recursive_func(fargs[i], 0, flags);
			}
			else if (S_ISREG(sb.st_mode))
				my_printf(&fargs[i], flags);
			i++;
		}
	}
}
