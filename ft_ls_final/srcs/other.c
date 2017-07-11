/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   other.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mameyer <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/14 14:26:01 by mameyer           #+#    #+#             */
/*   Updated: 2017/07/07 12:47:21 by mameyer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_ls.h"

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
