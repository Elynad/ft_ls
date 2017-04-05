/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_function.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mameyer <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/05 15:39:13 by mameyer           #+#    #+#             */
/*   Updated: 2017/04/05 23:00:59 by mameyer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_ls.h"

void		my_printf(char **str, t_flags flags)
{
	if (flags.f_r == 1)
		revalpha_sorting(str);
	if (flags.f_l == 0 && flags.f_t == 0)
		print_no_flags(str, flags);
	else if (flags.f_l == 1)
		print_l_flag(str, flags);
}

void		print_no_flags(char **str, t_flags flags)
{
	int		i;

	if (flags.f_a == 1)
		i = 0;
	else
		i = 2;
	while (str[i])
	{
		ft_putstr(str[i]);
		if (str[i + 1])
			ft_putchar('\t');
		i++;
	}
}

void		print_l_flag(char **str, t_flags flags)
{
	int				i;
	struct stat		sb;

	if (flags.f_a == 1)
		i = 0;
	else
		i = 2;
	while (str[i])
	{
		if (stat(str[i], &sb) == -1)
			error(3);
		print_type(str[i], sb);
		print_rights(str[i], sb);
		print_dependencies(str[i], sb);
		print_author(str[i], sb);
		print_group(str[i], sb);
		ft_putnbr(sb.st_size);
		ft_putchar('\t');
		print_time(str[i], sb);
		ft_putstr(str[i]);
		ft_putchar('\n');
		i++;
	}
}
