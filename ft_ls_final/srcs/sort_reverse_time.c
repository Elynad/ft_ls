/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_reverse_time.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mameyer <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/22 18:33:06 by mameyer           #+#    #+#             */
/*   Updated: 2017/07/07 12:04:26 by mameyer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_ls.h"

void		next_reverse_time_sort(t_lst *begin, t_lst *content, char *name,
		char *path)
{
	struct stat		sb;

	if (stat(set_path(name, path), &sb) == -1
			&& lstat(set_path(name, path), &sb) == -1)
		perror(path);
	if (content && stat(content->path, &(content->sb)) == -1)
		perror(content->path);
	if (content && content->next
			&& stat(content->next->path, &(content->next->sb)) == -1
			&& lstat(content->next->path, &(content->next->sb)) == -1)
		perror(content->path);
	if (content && content->sb.st_mtime > sb.st_mtime)
		sub_next_1(content, name, path);
	else if ((sub_reverse_time_sort_conditions(content, name, path) == 1)
			|| (content && content->sb.st_mtime < sb.st_mtime
			&& !content->next))
		sub_reverse_time_sort_2(content, name, path);
	else if (content && content->sb.st_mtime == sb.st_mtime)
		next_reverse_nano_sort(begin, content, name, path);
	else if (content->next)
		next_reverse_time_sort(begin, content->next, name, path);
}

void		next_reverse_nano_sort(t_lst *begin, t_lst *content, char *name,
		char *path)
{
	struct stat		sb;
	t_lst			*new;
	t_lst			*tmp;

	tmp = NULL;
	new = NULL;
	sub_reverse_nano_sort_1(content, name, path, &sb);
	if (content && content->next)
	{
		if (stat(content->next->path, &(content->next->sb)) == -1
				&& lstat(content->next->path, &(content->next->sb)) == -1)
			perror(content->next->path);
	}
	if (sub_rnsrtcnds(content, sb) == 1)
	{
		sub_reverse_nano_sort_mallocs(new, tmp);
		sub_next_1(content, name, path);
	}
	else if (sub_rnsrtcnds(content, sb) == 2 || sub_rnsrtcnds(content, sb) == 3)
		sub_reverse_nano_sort_2(content, name, path, sb);
	else if (content && content->sb.st_mtime == sb.st_mtime
			&& content->sb.st_mtimespec.tv_nsec == sb.st_mtimespec.tv_nsec)
		next_reverse_ascii_sort(begin, content, name, path);
	else if (content->next && content->next->sb.st_mtime == sb.st_mtime)
		next_reverse_nano_sort(begin, content->next, name, path);
}

void		next_reverse_ascii_sort(t_lst *begin, t_lst *content, char *name,
		char *path)
{
	struct stat		sb;

	if (stat(set_path(name, path), &sb) == -1
			&& lstat(set_path(name, path), &sb) == -1)
		perror(set_path(name, path));
	if (content && stat(content->path, &(content->sb)) == -1
			&& lstat(content->path, &(content->sb)) == -1)
		perror(set_path(name, path));
	if (content && content->next)
	{
		if (stat(content->next->path, &(content->next->sb)) == -1
				&& lstat(content->next->path, &(content->next->sb)) == -1)
			perror(content->next->path);
	}
	if (sub_rev_ascii_conds(content, sb, name) == 1
			|| sub_rev_ascii_conds(content, sb, name) == 2
			|| sub_rev_ascii_conds(content, sb, name) == 3)
		sub_reverse_ascii_sort_1(content, name, path, sb);
	else if (sub_rev_ascii_conds(content, sb, name) == 4)
		next_reverse_ascii_sort(begin, content->next, name, path);
}
