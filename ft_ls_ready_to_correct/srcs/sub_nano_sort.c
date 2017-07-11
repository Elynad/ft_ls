/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sub_nano_sort.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mameyer <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/22 17:11:21 by mameyer           #+#    #+#             */
/*   Updated: 2017/07/11 17:25:56 by mameyer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_ls.h"

int			sub_nsrtconds(t_lst *content, struct stat sb)
{
	if (content && content->sb.st_mtime == sb.st_mtime
			&& content->sb.st_mtimespec.tv_nsec < sb.st_mtimespec.tv_nsec)
		return (1);
	else if (content && content->sb.st_mtime == sb.st_mtime
			&& content->sb.st_mtimespec.tv_nsec > sb.st_mtimespec.tv_nsec
			&& content->next && content->next->sb.st_mtime == sb.st_mtime
			&& content->next->sb.st_mtimespec.tv_nsec < sb.st_mtimespec.tv_nsec)
		return (2);
	else if (content && content->sb.st_mtime == sb.st_mtime
			&& content->sb.st_mtimespec.tv_nsec > sb.st_mtimespec.tv_nsec
			&& !content->next)
		return (3);
	else
		return (0);
}

void		sub_nano_sort_2(t_lst *list, char *name, char *path, struct stat sb)
{
	t_lst		*new;

	if (sub_nsrtconds(list, sb) == 2)
	{
		if (!(new = malloc(sizeof(t_lst))))
			perror("malloc new link");
		new->next = list->next;
		list->next = new;
		new->name = ft_strdup(name);
		new->path = set_path(name, path);
	}
	else if (sub_nsrtconds(list, sb) == 3)
	{
		if (!(list->next = malloc(sizeof(t_lst))))
			perror("malloc new link");
		list->next->next = NULL;
		list->next->name = ft_strdup(name);
		list->next->path = set_path(name, path);
	}
}

void		sub_nano_sort_1(t_lst *content, char *name, char *path,
			struct stat *sb)
{
	if (lstat(set_path(name, path), &(*sb)) == -1
			&& content && lstat(content->path, &(content->sb)) == -1)
		error(set_path(name, path));
}

void		sub_nano_sort_mallocs(t_lst *new_elem, t_lst *tmp)
{
	if (!(new_elem = malloc(sizeof(t_lst))))
		perror("malloc new link");
	new_elem->next = NULL;
	if (!(tmp = malloc(sizeof(t_lst))))
		perror("malloc new link");
	tmp->next = NULL;
}
