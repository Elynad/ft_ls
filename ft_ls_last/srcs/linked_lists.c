/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   linked_lists.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mameyer <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/13 13:51:05 by mameyer           #+#    #+#             */
/*   Updated: 2017/07/08 17:19:53 by mameyer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_ls.h"

void		first(t_lst *content, char *name, char *path, int *tmp)
{
	content->name = ft_strdup(name);
	if (ft_strcmp(name, ".") != 0 && ft_strcmp(name, "..") != 0
			&& ft_strcmp(name, "./") != 0 && ft_strcmp(name, "../") != 0)
		content->path = set_path(name, path);
	else
		content->path = ft_strdup(name);
	if (stat(content->path, &(content->sb)) == -1
			&& lstat(content->path, &(content->sb)) == -1)
		perror(get_name(content->path));
	*tmp = 1;
}

static int	next_conds(t_lst *content, char *name)
{
	if (content->name && ft_strcmp(content->name, name) < 0
			&& content->next && content->next->name
			&& ft_strcmp(content->next->name, name) > 0)
		return (1);
	else
		return (0);
}

void		next(t_lst *content, char *name, char *path)
{
	t_lst		*new;

	new = NULL;
	if (content && content->name && ft_strcmp(content->name, name) > 0)
		sub_next_1(content, name, path);
	else if (next_conds(content, name) == 1)
	{
		if (!(new = malloc(sizeof(t_lst))))
			error("malloc");
		new->next = content->next;
		content->next = new;
		new->name = ft_strdup(name);
		new->path = set_path(name, path);
	}
	else if (!content->next)
	{
		if (!(content->next = malloc(sizeof(t_lst))))
			error("malloc");
		content->next->next = NULL;
		content->next->name = ft_strdup(name);
		content->next->path = set_path(name, path);
	}
	else if (content->next)
		next(content->next, name, path);
}

char		*set_path(char *name, char *path)
{
	char	*newpath;
	int		i;
	int		j;

	i = -1;
	j = -1;
	if (!(newpath = (char *)malloc(sizeof(char) * (ft_strlen(name)
						+ ft_strlen(path) + 2))))
		error(path);
	while (path[++i])
		newpath[i] = path[i];
	if (newpath[i - 1] != '/')
		newpath[i++] = '/';
	while (name[++j])
		newpath[i + j] = name[j];
	while (newpath[i + j])
	{
		newpath[i + j] = '\0';
		j++;
	}
	return (newpath);
}
