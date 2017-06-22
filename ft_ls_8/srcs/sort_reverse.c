/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_reverse.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mameyer <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/13 13:25:06 by mameyer           #+#    #+#             */
/*   Updated: 2017/06/22 16:11:42 by mameyer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_ls.h"

void		next_reverse(t_lst *content, char *name, char *path)
{
	t_lst		*new;

	new = NULL;
	if (ft_strcmp(content->name, name) < 0)
		sub_next_1(content, name, path);
	else if (ft_strcmp(content->name, name) > 0 && content->next
			&& ft_strcmp(content->next->name, name) < 0)
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
		next_reverse(content->next, name, path);
}
