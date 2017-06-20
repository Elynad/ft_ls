/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_time.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mameyer <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/20 14:27:13 by mameyer           #+#    #+#             */
/*   Updated: 2017/06/20 15:56:36 by mameyer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_ls.h"

void		next_conditions(t_lst *list, char *name, char *path, t_flags flags)
{
	t_lst		*new;

	if (!(new = malloc(sizeof(t_lst))))
		perror("");
	new->name = ft_strdup(name);
	new->path = set_path(name, path);
	new->next = NULL;
	if (flags.f_t == 1 && flags.f_r == 0)
		ft_putsec(&list, new);
}

void		ft_putsec(t_lst **content, t_lst *new_elem)
{
	t_lst		*begin;
	t_lst		*previous;

	begin = *content;
	previous = NULL;
	ft_timestamp(new_elem);
	if (*content == NULL)
		ft_addhead(content, new_elem);
	else
	{
		while (*content && (*content)->sb.st_mtime > new_elem->sb.st_mtime)
		{
			previous = *content;
			*content = (*content)->next;
		}
		if (*content == NULL)
			ft_addbetween(content, new_elem, begin, previous);
		else if ((*content)->sb.st_mtime < new_elem->sb.st_mtime)
			put_front(content, new_elem, begin, previous);
		else
			put_nsec(content, new_elem, begin, previous);
	}
}

void		ft_addbetween(t_lst **content, t_lst *new_elem, t_lst *begin,
			t_lst *previous)
{
	previous->next = new_elem;
	new_elem->next = *content;
	*content = begin;
}

void		put_front(t_lst **content, t_lst *new_elem, t_lst *begin,
			t_lst *previous)
{
	if (previous != NULL)
		previous->next = new_elem;
	new_elem->next = *content;
	*content = new_elem;
	if (previous != NULL)
		*content = begin;
}

void		put_nsec(t_lst **content, t_lst *new_elem, t_lst *begin,
			t_lst *previous)
{
	while (*content && (*content)->sb.st_mtime == new_elem->sb.st_mtime
			&& (*content)->sb.st_mtimespec.tv_nsec
			> new_elem->sb.st_mtimespec.tv_nsec)
	{
		previous = *content;
		*content = (*content)->next;
	}
	if (*content == NULL)
		ft_addhead(content, new_elem);
	else if ((*content)->sb.st_mtime < new_elem->sb.st_mtime
			|| (*content)->sb.st_mtimespec.tv_nsec
			< new_elem->sb.st_mtimespec.tv_nsec)
		put_front(content, new_elem, begin, previous);
	else
		ascii(content, new_elem, begin, previous);
}

void		ascii(t_lst **content, t_lst *new_elem, t_lst *begin,
			t_lst *previous)
{
	while (*content && (*content)->sb.st_mtime >= new_elem->sb.st_mtime
			&& (*content)->sb.st_mtimespec.tv_nsec
			== new_elem->sb.st_mtimespec.tv_nsec
			&& ft_strcmp((*content)->name, new_elem->name) < 0)
	{
		previous = *content;
		*content = (*content)->next;
	}
	if (*content == NULL)
	{
		previous->next = new_elem;
		new_elem->next = *content;
		*content = begin;
	}
	else if (ft_strcmp((*content)->name, new_elem->name) > 0
			|| (*content)->sb.st_mtime < new_elem->sb.st_mtime
			|| (*content)->sb.st_mtimespec.tv_nsec
			< new_elem->sb.st_mtimespec.tv_nsec)
		put_front(content, new_elem, begin, previous);
	else
	{
		new_elem->next = (*content)->next;
		(*content)->next = new_elem;
		*content = begin;
	}
}
