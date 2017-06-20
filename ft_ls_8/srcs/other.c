/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   other.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mameyer <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/14 14:26:01 by mameyer           #+#    #+#             */
/*   Updated: 2017/06/20 15:56:26 by mameyer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_ls.h"

char		*get_name(char *path)
{
	char		*str;
	int			i;
	int			k;

	k = 0;
	i = ft_strlen(path);
	while (i > 0 && path[i] != '/')
		i--;
	if (!(str = (char *)malloc(sizeof(char) * (ft_strlen(path) - i))))
		error(0, "other.c, get_name func");
	while (path[i + k])
	{
		str[k] = path[i + k];
		k++;
	}
	str[k] = '\0';
	return (str);
}

void		rec_high(t_lst *list, int *max)
{
	struct stat		sb;

	if (list->path)
	{
		if (stat(list->path, &sb) == -1 && lstat(list->path, &sb) == -1)
			perror(list->path);
		else
		{
			if (sb.st_nlink > *max)
				*max = sb.st_nlink;
			if (list->next)
				rec_high(list->next, max);
		}
	}
}

void		rec_longer_author_name(t_lst *list, int *max)
{
	struct stat		sb;
	struct passwd	*info;

	if (stat(list->path, &sb) == -1 && lstat(list->path, &sb) == -1)
		perror(list->path);
	else
	{
		info = getpwuid(sb.st_uid);
		if (ft_strlen(info->pw_name) > (size_t)*max)
			*max = ft_strlen(info->pw_name);
		if (list->next)
			rec_longer_author_name(list->next, max);
	}
}

void		rec_longer_group_name(t_lst *list, int *max)
{
	struct stat		sb;
	struct group	*group;

	if (stat(list->path, &sb) == -1 && lstat(list->path, &sb) == -1)
		perror(list->path);
	else
	{
		group = getgrgid(sb.st_gid);
		if (ft_strlen(group->gr_name) > (size_t)*max)
			*max = ft_strlen(group->gr_name);
		if (list->next)
			rec_longer_group_name(list->next, max);
	}
}

void		rec_highest_size(t_lst *list, int *max)
{
	struct stat		sb;

	if (stat(list->path, &sb) == -1 && lstat(list->path, &sb) == -1)
		perror(list->path);
	else
	{
		if (ft_strlen(ft_itoa(sb.st_size)) > (size_t)*max)
			*max = ft_strlen(ft_itoa(sb.st_size));
		if (list->next)
			rec_highest_size(list->next, max);
	}
}

void		get_today_date(int *today_date)
{
	struct stat			sb;

	if (stat(EXEC_NAME, &sb) == -1 && lstat(EXEC_NAME, &sb) == -1)
		perror(EXEC_NAME);
	*today_date = sb.st_mtime;
}

void		free_lst(t_lst *list)
{
	t_lst		*tmp;

	tmp = list->next;
	if (list != NULL && list->path && list->name)
	{
		free(list->name);
		free(list->path);
		free(list);
	}
	if (tmp)
		free_lst(tmp);
}

void		free_lst2(t_lst *list)
{
	t_lst	*tmp;
	t_lst	*tmpnext;

	tmp = list;
	while (tmp != NULL)
	{
		tmpnext = tmp->next;
		free(tmp->name);
		free(tmp);
		tmp = tmpnext;
	}
	free(tmp);
	free(tmpnext);
}

void		ft_timestamp(t_lst *new_elem)
{
	if ((stat(new_elem->path, &(new_elem->sb)) == -1)
			|| (lstat(new_elem->path, &(new_elem->sb)) == -1))
		perror(new_elem->path);
}

void		ft_addhead(t_lst **content, t_lst *new_elem)
{
	if (*content != NULL && new_elem != NULL)
		new_elem = *content;
	*content = new_elem;
}
