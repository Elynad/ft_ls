/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   other.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mameyer <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/14 14:26:01 by mameyer           #+#    #+#             */
/*   Updated: 2017/07/11 17:38:20 by mameyer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_ls.h"
#include <malloc/malloc.h>

void		rec_high(t_lst *list, int *max)
{
	struct stat		sb;

	if (list && list->path)
	{
		if (lstat(list->path, &sb) == -1)
			error(list->path);
		else
		{
			if (sb.st_nlink > *max)
				*max = sb.st_nlink;
			if (list && list->next && list->next->path)
				rec_high(list->next, max);
		}
	}
}

void		rec_longer_author_name(t_lst *list, int *max)
{
	struct stat		sb;
	struct passwd	*info;

	if (lstat(list->path, &sb) == -1)
		error(list->path);
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

	if (lstat(list->path, &sb) == -1)
		error(list->path);
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

	if (lstat(list->path, &sb) == -1)
		error(list->path);
	else
	{
		if (ft_strlen(ft_itoa(sb.st_size)) > (size_t)*max)
			*max = ft_strlen(ft_itoa(sb.st_size));
		if (list->next)
			rec_highest_size(list->next, max);
	}
}
