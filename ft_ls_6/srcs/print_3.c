/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_3.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mameyer <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/20 18:17:07 by mameyer           #+#    #+#             */
/*   Updated: 2017/05/20 18:21:40 by mameyer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_ls.h"

void		print_rights(struct stat sb)
{
	print_usr_rights(sb);
	print_grp_rights(sb);
	print_oth_rights(sb);
	ft_putchar('\t');
}

void		print_usr_rights(struct stat sb)
{
	if (sb.st_mode & S_IRUSR)
		ft_putchar('r');
	else
		ft_putchar('-');
	if (sb.st_mode & S_IWUSR)
		ft_putchar('w');
	else
		ft_putchar('-');
	if (sb.st_mode & S_IXUSR)
		ft_putchar('x');
	else
		ft_putchar('-');
}

void		print_grp_rights(struct stat sb)
{
	if (sb.st_mode & S_IRGRP)
		ft_putchar('r');
	else
		ft_putchar('-');
	if (sb.st_mode & S_IWGRP)
		ft_putchar('w');
	else
		ft_putchar('-');
	if (sb.st_mode & S_IXGRP)
		ft_putchar('x');
	else
		ft_putchar('-');
}

void		print_oth_rights(struct stat sb)
{
	if (sb.st_mode & S_IROTH)
		ft_putchar('r');
	else
		ft_putchar('-');
	if (sb.st_mode & S_IWOTH)
		ft_putchar('w');
	else
		ft_putchar('-');
	if (sb.st_mode & S_IXOTH)
		ft_putchar('x');
	else
		ft_putchar('-');
}
