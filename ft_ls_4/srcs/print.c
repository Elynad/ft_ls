/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mameyer <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/24 19:25:06 by mameyer           #+#    #+#             */
/*   Updated: 2017/04/26 16:02:16 by mameyer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_ls.h"

void		my_printf(char **str, t_flags flags)
{
	if (flags.f_l == 0 && flags.f_t == 0)
		print_1(str, flags);
	else if (flags.f_l == 1)
		print_2(str, flags);
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
	ft_putchar('\n');
}

void		print_2(char **str, t_flags flags)
{
	int				i;
	struct stat		sb;

	i = find_index(flags, str);
	if (flags.f_r == 1)
	{
		while (str[i])
			i++;
		i--;
	}
	else if (flags.f_a == 0 && flags.f_r == 0)
		i = find_index(flags, str);
	while (str[i] && i >= 0)
	{
		if (stat(str[i], &sb) == -1)
			error(5, "");
		print_l(str[i], sb);
		if (flags.f_r == 1 && flags.f_a == 0 && i == 2)
			break ;
		if (flags.f_r == 1)
			i--;
		else
			i++;
	}
}

void		print_l(char *str, struct stat sb)
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
