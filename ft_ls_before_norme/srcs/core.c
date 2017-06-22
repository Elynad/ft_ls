/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   core.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mameyer <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/13 13:29:56 by mameyer           #+#    #+#             */
/*   Updated: 2017/06/22 15:11:50 by mameyer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_ls.h"

void		core(char *path, t_flags flags)
{
	t_lst			*content;
	struct stat		sb;

	content = NULL;
	if (stat(path, &sb) == -1 && lstat(path, &sb) == -1)
		perror(path);
	if (S_ISDIR(sb.st_mode) || ft_strcmp(path, "./") == 0)
	{
		if (ft_strcmp(path, "./") != 0)
		{
			ft_putstr(path);
			ft_putstr(":\n");
		}
		if (sb.st_mode & S_IRUSR)
		{
			content = open_directory(path, flags);
			my_printf(content, flags);
		}
		else
			perror(get_name(path));
	}
	else
	{
		ft_putstr(path);
		ft_putchar('\n');
	}
	if (flags.f_R == 1 && sb.st_mode & S_IRUSR)
	{
		ft_putchar('\n');
		recursive_func(content, flags);
	}
	free_lst(content);
}

t_lst		*open_directory(char *path, t_flags flags)
{
	t_lst		*content;
	t_fold		fold;
	int			i;

	i = 0;
	init_fold_struct(&fold);
	if (!(content = malloc(sizeof(t_lst))))
		perror(path);
	content->name = NULL;
	content->next = NULL;
	if ((fold.rep = opendir(path)) == NULL)
		perror(get_name(path));
	else
	{
		sub_open_dir(&fold, content, flags, path);
		if (closedir(fold.rep) == -1)
			perror(get_name(path));
	}
	return (content);
}

void		recursive_func(t_lst *content, t_flags flags)
{
	struct stat		sb;

	if (content->path && content->name)
	{
		if (ft_strcmp(content->path, ".") != 0
				&& ft_strcmp(content->path, "./") != 0
				&& ft_strcmp(content->path, "..") != 0
				&& ft_strcmp(content->path, "../") != 0)
		{
			if (stat(content->path, &sb) == -1
					&& lstat(content->path, &sb) == -1)
				perror(get_name(content->path));
			if (S_ISDIR(sb.st_mode))
				core(content->path, flags);
		}
		if (content->next)
			recursive_func(content->next, flags);
	}
}
