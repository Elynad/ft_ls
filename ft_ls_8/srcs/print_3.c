/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_3.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mameyer <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/14 16:42:39 by mameyer           #+#    #+#             */
/*   Updated: 2017/06/19 13:08:25 by mameyer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_ls.h"

void		print_dependencies(t_lst *list, t_print *infos)
{			// review => strange
	struct stat			sb;
	int					spaces;

	if (stat(list->path, &sb) == -1 && lstat(list->path, &sb) == -1)
		perror(list->path);
	spaces = 2 + ft_strlen(ft_itoa(infos->highest_dep))
		- ft_strlen(ft_itoa(sb.st_nlink));
	while (spaces > 0)
	{
		ft_putchar(' ');
		spaces--;
	}
	ft_putnbr(sb.st_nlink);
}

void		print_author(struct stat sb, t_print *infos)
{
	struct passwd		*passwd;
	int					spaces;

	ft_putchar(' ');
	passwd = getpwuid(sb.st_uid);
	spaces = 2 + infos->longer_author_name - (ft_strlen(passwd->pw_name));
	ft_putstr(passwd->pw_name);
	while (spaces > 0)
	{
		ft_putchar(' ');
		spaces--;
	}
}

void		print_group(struct stat sb, t_print *infos)
{
	struct group		*group;
	int					spaces;

//	ft_putstr("  ");
	group = getgrgid(sb.st_gid);
	spaces = 2 + infos->longer_group_name - (ft_strlen(group->gr_name));
	ft_putstr(group->gr_name);
	while (spaces > 0)
	{
		ft_putchar(' ');
		spaces--;
	}
}

void		print_size(struct stat sb, t_print *infos)
{
	int					spaces;

	spaces = infos->highest_size - (ft_strlen(ft_itoa(sb.st_size)));
	while (spaces > 0)
	{
		ft_putchar(' ');
		spaces--;
	}
	ft_putnbr(sb.st_size);
	ft_putchar(' ');
}

void		print_time(struct stat sb, t_print *infos)
{
	char		*str;
	int			i;

	i = 3;
	str = ft_strdup(ctime(&sb.st_mtime));
	while (i <= 10)
	{
		ft_putchar(str[i]);
		i++;
	}
	if (infos->today_date - sb.st_mtime < DIFFERENCE)
	{
		i = 11;
		while (i <= 15)
		{
			ft_putchar(str[i]);
			i++;
		}
	}
	else
	{
		i = 20;
		ft_putchar(' ');
		while (i < 24)
		{
			ft_putchar(str[i]);
			i++;
		}
	}
	free(str);
}
