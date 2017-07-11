/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sub_core.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mameyer <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/21 12:16:58 by mameyer           #+#    #+#             */
/*   Updated: 2017/07/08 21:48:34 by mameyer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_ls.h"

void		sub_print_time(char *str)
{
	int		i;

	i = 20;
	ft_putchar(' ');
	while (i < 24)
	{
		ft_putchar(str[i]);
		i++;
	}
}

void		sub_open_dir(t_fold *fold, t_lst *list, t_flags flags, char *path)
{
	int		i;

	while ((fold->readfile = readdir(fold->rep)) != NULL)
	{
		if ((fold->readfile->d_name[0] != '.' && flags.f_a == 0)
				|| flags.f_a == 1)
		{
			if (i == 0)
				first(list, fold->readfile->d_name, path, &i);
			else
				next_conditions(list, fold->readfile->d_name, path, flags);
		}
	}
}

void		next_conditions(t_lst *list, char *name, char *path, t_flags flags)
{
	t_lst		*new;

	if (!(new = malloc(sizeof(t_lst))))
		perror("malloc new link");
	new->name = ft_strdup(name);
	new->path = set_path(name, path);
	new->next = NULL;
	if (flags.f_t == 1 && flags.f_r == 0)
		next_time_sort(list, list, name, path);
	else if (flags.f_t == 1 && flags.f_r == 1)
		next_reverse_time_sort(list, list, name, path);
	else if (flags.f_t == 0 && flags.f_r == 1)
		next_reverse(list, name, path);
	else
		next(list, name, path);
}

void		sub_core_isdir(t_lst **lst, struct stat sb, char *path,
		t_flags flags)
{
	if (ft_strcmp(path, "./") != 0 && ((flags.one == 0) || (flags.one != 1
					&& flags.f_rec == 1)))
	{
		ft_putstr(path);
		ft_putstr(":\n");
	}
	if (sb.st_mode & S_IRUSR)
	{
		*lst = open_directory(path, flags);
		my_printf(*lst, flags, 0);
	}
	else
		perror(get_name(path));
}
