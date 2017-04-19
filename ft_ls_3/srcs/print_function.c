/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_function.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mameyer <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/05 15:39:13 by mameyer           #+#    #+#             */
/*   Updated: 2017/04/19 13:40:34 by mameyer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_ls.h"

void		my_printf(char **str, t_flags flags)
{
	if (flags.f_l == 0 && flags.f_t == 0)
		print_no_flags(str, flags);
	else if (flags.f_l == 1)
		print_l_flag(str, flags);
}

void		print_no_flags(char **str, t_flags flags)
{
	int		i;

	i = find_index(flags);
	if (flags.f_r == 1)
	{
		while (str[i])
			i++;
		i--;
	}
	while (str[i] && i >= 0)
	{
		ft_putstr(str[i]);
		if ((str[i + 1] && flags.f_r == 0)
				|| (flags.f_r == 1 && flags.f_a == 0 && i > 2)
				|| (flags.f_r == 1 && flags.f_a == 1 && i > 0))
			ft_putchar('\t');
		if (flags.f_r == 1 && flags.f_a == 0 && i == 2)
			break ;
		if (flags.f_r == 1)
			i--;
		else
			i++;
	}
	ft_putchar('\n');
}

void		print_l_flag(char **str, t_flags flags)
{
	int				i;
	struct stat		sb;

	i = 0;
	if (flags.f_r == 1)
	{
		while (str[i])
			i++;
		i--;
	}
	else if (flags.f_a == 0 && flags.f_r == 0)
		i = 2;
	while (str[i] && i >= 0)
	{
		if (stat(str[i], &sb) == -1)
			error(3);
		lprint_2(str[i], sb);
		if (flags.f_r == 1 && flags.f_a == 0 && i == 2)
			break ;
		if (flags.f_r == 1)
			i--;
		else
			i++;
	}
}

void		lprint_2(char *str, struct stat sb)
{
	print_type(str, sb);
	print_rights(str, sb);
	print_dependencies(str, sb);
	print_author(str, sb);
	print_group(str, sb);
	ft_putnbr(sb.st_size);
	ft_putchar('\t');
	print_time(str, sb);
	ft_putstr(str);
	ft_putchar('\n');
}
