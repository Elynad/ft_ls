/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   core.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mameyer <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/20 16:59:27 by mameyer           #+#    #+#             */
/*   Updated: 2017/05/20 18:02:11 by mameyer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_ls.h"

void		core_func(char *path, t_flags flags, int type)
{
	struct stat		sb;
	t_lst			*content;

	if (stat(path, &sb) == -1 && lstat(path, &sb) == -1)
		error_1(3, path);
	else if (S_ISDIR(sb.st_mode))
	{
//		content = open_directory(path, flags, type);
		my_printf(open_directory(path, flags, type), flags);
		if (flags.f_R == 1)
			recursive_func(content, flags);
	}
	else if (S_ISREG(sb.st_mode))
	{
		ft_putstr(path);
		ft_putchar('\n');
	}
}

t_lst		*open_directory(char *path, t_flags flags, int type)
{
	t_fold			fold;
	t_lst			*content;
	int				i;

	i = 0;
	init_fold_struct(&fold);
	if (!(content = malloc(sizeof(t_lst))))
		error_1(2, "core.c - line 42");
	if ((fold.rep = opendir(path)) == NULL)
		error_1(4, "core.c - line 44");
	while ((fold.readfile = readdir(fold.rep)) != NULL)
	{
		if ((fold.readfile->d_name[0] != '.' && flags.f_a == 0)
				|| flags.f_a == 1)
		{
			if (i == 0)
				first_elem(content, fold.readfile->d_name, path, &i);
			else
				new_elem(content, fold.readfile->d_name, path);
		}
	}
	if (closedir(fold.rep) == -1)
		error_1(5, "core.c - line 50");
	return (content);
}

void		recursive_func(t_lst *content, t_flags flags)
{
	struct stat		sb;

	if (stat(content->path, &sb) == -1 && lstat(content->path, &sb) == -1)
		error_1(3, content->path);
	else if (S_ISDIR(sb.st_mode) && check_if_empty(content->path, flags) == 0)
	{
		ft_putstr(content->path);
		ft_putstr(":\n");
		if (content->next)
			core_func(content->path, flags, 0);
		else
			core_func(content->path, flags, 1);
	}
	if (content->next)
		recursive_func(content->next, flags);
}
