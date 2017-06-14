/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_3.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mameyer <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/14 16:42:39 by mameyer           #+#    #+#             */
/*   Updated: 2017/06/14 17:21:30 by mameyer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_ls.h"

void		print_dependencies(t_lst *list)
{
	struct stat		sb;
	long			highest;

	highest = 0;
	if (stat(list->path, &sb) == -1 && lstat(list->path, &sb) == -1)
		perror(list->path);
	highest = get_highest_deps(list, &highest);

}

void		print_author(struct stat sb)
{
	struct passwd		*info;

	info = getpwuid(sb.st_uid);
	ft_putstr(info->pw_name);
	ft_putchar('\t');
}

void		print_group(struct stat sb)
{
	struct group		*info;

	info = getgrgid(sb.st_gid);
	ft_putstr(info->gr_name);
	ft_putchar('\t');
}
