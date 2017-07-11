/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sub_ascii_sort.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mameyer <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/22 17:53:14 by mameyer           #+#    #+#             */
/*   Updated: 2017/07/08 16:04:14 by mameyer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_ls.h"

int			sub_asciisrtconds(t_lst *list, struct stat sb, char *name)
{
	if (list && list->sb.st_mtime == sb.st_mtime
			&& list->sb.st_mtimespec.tv_nsec == sb.st_mtimespec.tv_nsec
			&& ft_strcmp(list->name, name) < 0)
		return (1);
	else if (list && list->sb.st_mtime == sb.st_mtime
			&& list->sb.st_mtimespec.tv_nsec == sb.st_mtimespec.tv_nsec
			&& list->next && list->next->sb.st_mtime == sb.st_mtime
			&& list->next->sb.st_mtimespec.tv_nsec == sb.st_mtimespec.tv_nsec
			&& ft_strcmp(list->name, name) > 0
			&& ft_strcmp(list->next->name, name) < 0)
		return (2);
	else if (list && list->sb.st_mtime == sb.st_mtime
			&& list->sb.st_mtimespec.tv_nsec == sb.st_mtimespec.tv_nsec
			&& ft_strcmp(list->name, name) > 0 && !list->next)
		return (3);
	else if (list && list->sb.st_mtime == sb.st_mtime
			&& list->sb.st_mtimespec.tv_nsec == sb.st_mtimespec.tv_nsec
			&& list->next)
		return (4);
	else
		return (0);
}

void		sub_ascii_sort_1(t_lst *lst, char *name, char *path, struct stat sb)
{
	t_lst		*new;

	if (sub_asciisrtconds(lst, sb, name) == 1)
		sub_next_1(lst, name, path);
	else if (sub_asciisrtconds(lst, sb, name) == 2)
	{
		if (!(new = malloc(sizeof(t_lst))))
			perror("malloc new link");
		new->next = lst->next;
		lst->next = new;
		new->name = ft_strdup(name);
		new->path = set_path(name, path);
	}
	else if (sub_asciisrtconds(lst, sb, name) == 3)
	{
		if (!(lst->next = malloc(sizeof(t_lst))))
			perror("malloc new link");
		lst->next->next = NULL;
		lst->next->name = ft_strdup(name);
		lst->next->path = set_path(name, path);
	}
}
