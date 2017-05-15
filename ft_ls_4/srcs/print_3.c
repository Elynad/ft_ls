/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_3.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mameyer <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/25 16:59:59 by mameyer           #+#    #+#             */
/*   Updated: 2017/04/25 17:06:43 by mameyer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_ls.h"

void		print_rights(char *str, struct stat sb)
{
	print_usr_rights(str, sb);
	print_grp_rights(str, sb);
	print_oth_rights(str, sb);
	ft_putchar('\t');
}

void		print_usr_rights(char *str, struct stat sb)
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

void		print_grp_rights(char *str, struct stat sb)
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

void		print_oth_rights(char *str, struct stat sb)
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
