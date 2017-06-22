/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sub_time_sort.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mameyer <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/22 16:27:34 by mameyer           #+#    #+#             */
/*   Updated: 2017/06/22 17:11:08 by mameyer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_ls.h"

int			sub_time_sort_conditions(t_lst *content, char *name, char *path)
{
	struct stat		sb;

	if (stat(set_path(name, path), &sb) == -1
			&& lstat(set_path(name, path), &sb) == -1)
		perror("");
	if (content && content->sb.st_mtime > sb.st_mtime && content->next
			&& content->next->sb.st_mtime < sb.st_mtime)
		return (1);
	else
		return (0);
}

void		sub_time_sort_2(t_lst *content, char *name, char *path)
{
	t_lst			*new;
	struct stat		sb;

	if (stat(set_path(name, path), &sb) == -1
			&& lstat(set_path(name, path), &sb) == -1)
		perror(set_path(name, path));
	if (sub_time_sort_conditions(content, name, path) == 1)
	{
		if (!(new = malloc(sizeof(t_lst))))
			perror("");
		new->next = content->next;
		content->next = new;
		new->name = ft_strdup(name);
		new->path = set_path(name, path);
	}
	else if (content && content->sb.st_mtime > sb.st_mtime && !content->next)
	{
		if (!(content->next = malloc(sizeof(t_lst))))
			perror("");
		content->next->next = NULL;
		content->next->name = ft_strdup(name);
		content->next->path = set_path(name, path);
	}
}
