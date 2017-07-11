/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   core.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mameyer <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/13 13:29:56 by mameyer           #+#    #+#             */
/*   Updated: 2017/07/11 17:37:47 by mameyer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_ls.h"

void		core(char *path, t_flags flags)
{
	t_lst			*content;
	struct stat		sb;

	content = NULL;
	if (lstat(path, &sb) == -1)
		error(path);
	else
	{
		if (sub_core(sb, path, &content, flags) == 1)
			content = set_elem(path, flags);
		if (flags.f_rec == 1 && sb.st_mode & S_IRUSR && S_ISDIR(sb.st_mode))
		{
			ft_putchar('\n');
			recursive_func(content, flags);
		}
	}
	if (content)
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

static int	check_hidden(char *path)
{
	int		i;

	i = ft_strlen(path) - 1;
	if ((path[i] == '.' && path[i - 1] == '/')
			|| (path[i] == '.' && path[i - 1] == '.' && path[i - 2] == '/'))
		return (1);
	else
		return (0);
}

void		recursive_func(t_lst *content, t_flags flags)
{
	struct stat		sb;

	if (content->path && content->name)
	{
		if (ft_strcmp(content->path, ".") != 0
				&& check_hidden(content->path) != 1)
		{
			if (lstat(content->path, &sb) == -1)
				error(content->path);
			else if (S_ISDIR(sb.st_mode))
				core(content->path, flags);
		}
		if (content->next)
			recursive_func(content->next, flags);
	}
}
