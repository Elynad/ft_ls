/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   core.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mameyer <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/13 13:29:56 by mameyer           #+#    #+#             */
/*   Updated: 2017/06/13 17:18:21 by mameyer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_ls.h"

void		core(char *path, t_flags flags)
{
	t_lst		*content;
	struct stat	sb;

	if (stat(path, &sb) == -1 && lstat(path, &sb) == -1)
		error(4, content->path);
	if (S_ISDIR(sb.st_mode) || ft_strcmp(path, "./") == 0)
	{
		if (ft_strcmp(path, "./") != 0)
		{
			ft_putstr(path);
			ft_putstr(":\n");
		}
		content = open_directory(path, flags);
		print_test(content);
	}
	else
	{
		ft_putstr(path);
		ft_putchar('\n');
	}
	if (flags.f_R == 1)
	{
		ft_putchar('\n');
		recursive_func(content, flags);
	}
}

t_lst		*open_directory(char *path, t_flags flags)
{
	t_lst		*content;
	t_fold		fold;
	int			i;

	i = 0;
	init_fold_struct(&fold);
	if (!(content = malloc(sizeof(t_lst))))
		error(0, "core.c, open_directory func");
	content->name = NULL;
	content->next = NULL;
	if ((fold.rep = opendir(path)) == NULL)
		error(2, path);
	while ((fold.readfile = readdir(fold.rep)) != NULL)
	{
		if ((fold.readfile->d_name[0] != '.' && flags.f_a == 0)
				|| flags.f_a == 1)
		{
			if (i == 0)
				first(content, fold.readfile->d_name, path, &i);
			else
				next(content, fold.readfile->d_name, path);
		}
	}
	if (closedir(fold.rep) == -1)
		error(3, path);
	return (content);
}

void		recursive_func(t_lst *content, t_flags flags)
{
	struct stat		sb;

	if (content->path)
	{
		if (stat(content->path, &sb) == -1 && lstat(content->path, &sb) == -1)
			error(4, content->path);
		if (S_ISDIR(sb.st_mode))
			core(content->path, flags);
	}
	if (content->next)
		recursive_func(content->next, flags);
}
