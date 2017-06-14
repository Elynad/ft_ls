/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   linked_lists.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mameyer <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/13 13:51:05 by mameyer           #+#    #+#             */
/*   Updated: 2017/06/14 14:57:59 by mameyer          ###   ########.fr       */
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

void		next(t_lst *content, char *name, char *path)
{
	if (content->next)
		next(content->next, name, path);
	else
	{
		if (!(content->next = malloc(sizeof(t_lst))))
			error(0, "linked_lists.c, next func");
		content->next->name = ft_strdup(name);
		if (ft_strcmp(name, ".") != 0 && ft_strcmp(name, "..") != 0
				&& ft_strcmp(name, "./") != 0 && ft_strcmp(name, "../") != 0)
			content->next->path = set_path(name, path);
		else
			content->next->path = ft_strdup(name);
		if (stat(content->path, &(content->sb)) == -1
				&& lstat(content->path, &(content->sb)) == -1)
			perror(get_name(content->path));
	}
}

char		*set_path(char *name, char *path)
{
	char	*newpath;
	int		i;
	int		j;

	i = 0;
	j = 0;
	if (!(newpath = (char *)malloc(sizeof(char) * (ft_strlen(name)
						+ ft_strlen(path) + 2))))
		error(0, "linked_lists.c, set_path func");
	while (path[i])
	{
		newpath[i] = path[i];
		i++;
	}
	if (newpath[i - 1] != '/')
	{
		newpath[i] = '/';
		i++;
	}
	while (name[j])
	{
		newpath[i + j] = name[j];
		j++;
	}
	while (newpath[i + j])
	{
		newpath[i + j] = '\0';
		j++;
	}
	return (newpath);
}
