/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_1.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mameyer <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/20 17:57:47 by mameyer           #+#    #+#             */
/*   Updated: 2017/05/22 17:35:43 by mameyer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_ls.h"

void		my_printf(t_lst *list, t_flags flags)
{
	// sort
	if (flags.f_l == 0)
		print(list, flags);
	else if (flags.f_l == 1)
		print_l(list, flags);
}

void		print(t_lst *list, t_flags flags)
{
	ft_putstr(list->name);
	if (list->next)
		ft_putchar('\t');
	else
		ft_putchar('\n');
	if (list->next)
		print(list->next, flags);
}

void		print_l(t_lst *list, t_flags flags)
{
	struct stat		sb;

	if (stat(list->path, &sb) == -1 || lstat(list->path, &sb) == -1)
		error_1(3, list->path);
	else
	{
		print_l2(list->name, list->path, sb);
		if (list->next)
			print_l(list->next, flags);
	}
}

void		print_l2(char *name, char *path, struct stat sb)
{
	print_type(sb);
	print_rights(sb);
	print_dependencies(path, sb);
	print_author(sb);
	print_group( sb);
	ft_putnbr(sb.st_size);
	ft_putchar('\t');
	print_time(sb);
	ft_putstr(name);
	ft_putchar('\n');
}
