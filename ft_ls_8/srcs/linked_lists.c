/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   linked_lists.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mameyer <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/13 13:51:05 by mameyer           #+#    #+#             */
/*   Updated: 2017/06/22 15:57:47 by mameyer          ###   ########.fr       */
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
	t_lst		*new;

	new = NULL;
	if (ft_strcmp(content->name, name) > 0)
		sub_next_1(content, name, path);
	else if (ft_strcmp(content->name, name) < 0 && content->next
			&& ft_strcmp(content->next->name, name) > 0)
	{
		if (!(new = malloc(sizeof(t_lst))))
			perror("");
		new->next = content->next;
		content->next = new;
		new->name = ft_strdup(name);
		new->path = set_path(name, path);
	}
	else if (!content->next)
	{
		if (!(content->next = malloc(sizeof(t_lst))))
			perror("");
		content->next->next = NULL;
		content->next->name = ft_strdup(name);
		content->next->path = set_path(name, path);
	}
	else
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
		perror(path);
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
