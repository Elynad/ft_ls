/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mameyer <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/13 13:25:06 by mameyer           #+#    #+#             */
/*   Updated: 2017/06/20 14:27:06 by mameyer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_ls.h"
/*
void		sort_time(t_lst *content, char *name, char *path)
{
	
}

void		sort_reverse_time(t_lst *content, char *name, char *path)
{
	
}*/

void		next_reverse(t_lst *content, char *name, char *path)
{
	t_lst		*new;
	t_lst		*tmp;

	new = NULL;
	if (ft_strcmp(content->name, name) < 0)
	{
		// Si content->name est avant name, name vient avant content
		if (!(tmp = malloc(sizeof(t_lst))))
			perror("");
		if (!(new = malloc(sizeof(t_lst))))
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
	else if (ft_strcmp(content->name, name) > 0 && content->next
			&& ft_strcmp(content->next->name, name) < 0)
	{
		// Si content est apres name et que name est avant content->next
		if (!(new = malloc(sizeof(t_lst))))
			perror("");
		new->next = content->next;
		content->next = new;
		new->name = ft_strdup(name);
		new->path = set_path(name, path);
	}
	else if (!content->next)
	{
		// Si il n'y a plus d'elements suivants, new devient le dernier element
		if (!(content->next = malloc(sizeof(t_lst))))
			perror("");
		content->next->next = NULL;
		content->next->name = ft_strdup(name);
		content->next->path = set_path(name, path);
	}
	else
		next_reverse(content->next, name, path);
}
