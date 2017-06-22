/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_time.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mameyer <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/21 12:39:14 by mameyer           #+#    #+#             */
/*   Updated: 2017/06/22 16:12:06 by mameyer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_ls.h"

void		next_time_sort(t_lst *begin, t_lst *content, char *name, char *path)
{
	struct stat			sb;
	t_lst				*new;
	t_lst				*tmp;

	new = NULL;
	tmp = NULL;
	if (stat(set_path(name, path), &sb) == -1
			&& lstat(set_path(name, path), &sb) == -1)
		perror(path);
	if (content && stat(content->path, &(content->sb)) == -1
			&& lstat(content->path, &(content->sb)) == -1)
		perror(content->path);
	if (content && content->next)
	{
		if (stat(content->next->path, &(content->next->sb)) == -1
			&& lstat(content->next->path, &(content->next->sb)) == -1)
				perror(content->path);
	}
	if (content && content->sb.st_mtime < sb.st_mtime)
	{
		if (!(new = malloc(sizeof(t_lst))))
			perror("");
		if (!(tmp = malloc(sizeof(t_lst))))
			perror("");
		tmp->name = ft_strdup(content->name);
		tmp->path = ft_strdup(content->path);
		tmp->next = content->next;
		free(content->name);
		content->name = ft_strdup(name);
		free(content->path);
		content->path = set_path(name, path);;
		content->next = tmp;
	}
	else if (content && content->sb.st_mtime > sb.st_mtime && content->next
			&& content->next->sb.st_mtime < sb.st_mtime)
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
	else if (content && content->sb.st_mtime == sb.st_mtime)
		next_nano_sort(begin, content, name, path);
	else if (content->next)
	{
		next_time_sort(begin, content->next, name, path);
	}
}

void		next_nano_sort(t_lst *begin, t_lst *content, char *name, char *path)
{
	struct stat		sb;
	t_lst			*new;
	t_lst			*tmp;

	if (stat(set_path(name, path), &sb) == -1
			&& lstat(set_path(name, path), &sb) == -1)
		perror(set_path(name, path));
	if (content && stat(content->path, &(content->sb)) == -1
			&& lstat(content->path, &content->sb) == -1)
		perror(content->path);
	if (content && content->next)
	{
		if (stat(content->next->path, &(content->next->sb)) == -1
				&& lstat(content->next->path, &(content->next->sb)) == -1)
			perror(content->next->path);
	}
	if (content && content->sb.st_mtime == sb.st_mtime
			&& content->sb.st_mtimespec.tv_nsec < sb.st_mtimespec.tv_nsec)
	{
		if (!(new = malloc(sizeof(t_lst))))
			perror("");
		if (!(tmp = malloc(sizeof(t_lst))))
			perror("");
		tmp->name = ft_strdup(content->name);
		tmp->path = ft_strdup(content->path);
		tmp->next = content->next;
		free(content->name);
		content->name = ft_strdup(name);
		free(content->path);
		content->path = set_path(name, path);
		content->next = tmp;
	}
	else if (content && content->sb.st_mtime == sb.st_mtime
			&& content->sb.st_mtimespec.tv_nsec > sb.st_mtimespec.tv_nsec
			&& content->next && content->next->sb.st_mtime == sb.st_mtime
			&& content->next->sb.st_mtimespec.tv_nsec < sb.st_mtimespec.tv_nsec)
	{
		if (!(new = malloc(sizeof(t_lst))))
			perror("");
		new->next = content->next;
		content->next = new;
		new->name = ft_strdup(name);
		new->path = set_path(name, path);
	}
	else if (content && content->sb.st_mtime == sb.st_mtime
			&& content->sb.st_mtimespec.tv_nsec > sb.st_mtimespec.tv_nsec
			&& !content->next)
	{
		if (!(content->next = malloc(sizeof(t_lst))))
			perror("");
		content->next->next = NULL;
		content->next->name = ft_strdup(name);
		content->next->path = set_path(name, path);
	}
	else if (content && content->sb.st_mtime == sb.st_mtime
			&& content->sb.st_mtimespec.tv_nsec == sb.st_mtimespec.tv_nsec)
		next_ascii_sort(begin, content, name, path);
	else if (content->next && content->next->sb.st_mtime == sb.st_mtime)
		next_nano_sort(begin, content->next, name, path);
}

void		next_ascii_sort(t_lst *begin, t_lst *content, char *name, char *path)
{
	struct stat			sb;
	t_lst				*new;
	t_lst				*tmp;

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
	if (content && content->sb.st_mtime == sb.st_mtime
			&& content->sb.st_mtimespec.tv_nsec == sb.st_mtimespec.tv_nsec
			&& ft_strcmp(content->name, name) < 0)
	{
		if (!(new = malloc(sizeof(t_lst))))
			perror("");
		if (!(tmp = malloc(sizeof(t_lst))))
			perror("");
		tmp->name = ft_strdup(content->name);
		tmp->path = ft_strdup(content->path);
		tmp->next = content->next;
		free(content->name);
		content->name = ft_strdup(name);
		free(content->path);
		content->path = set_path(name, path);
		content->next = tmp;
	}
	else if (content && content->sb.st_mtime == sb.st_mtime
			&& content->sb.st_mtimespec.tv_nsec == sb.st_mtimespec.tv_nsec
			&& content->next && content->next->sb.st_mtime == sb.st_mtime
			&& content->next->sb.st_mtimespec.tv_nsec == sb.st_mtimespec.tv_nsec
			&& ft_strcmp(content->name, name) > 0
			&& ft_strcmp(content->next->name, name) < 0)
	{
		if (!(new = malloc(sizeof(t_lst))))
			perror("");
		new->next = content->next;
		content->next = new;
		new->name = ft_strdup(name);
		new->path = set_path(name, path);
	}
	else if (content && content->sb.st_mtime == sb.st_mtime
			&& content->sb.st_mtimespec.tv_nsec == sb.st_mtimespec.tv_nsec
			&& ft_strcmp(content->name, name) > 0 && !content->next)
	{
		if (!(content->next = malloc(sizeof(t_lst))))
			perror("");
		content->next->next = NULL;
		content->next->name = ft_strdup(name);
		content->next->path = set_path(name, path);
	}
	else if (content && content->sb.st_mtime == sb.st_mtime
			&& content->sb.st_mtimespec.tv_nsec == sb.st_mtimespec.tv_nsec
			&& content->next)
	{
		next_ascii_sort(begin, content->next, name, path);
	}
}
