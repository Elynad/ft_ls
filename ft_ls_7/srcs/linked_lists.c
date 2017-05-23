/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   linked_lists.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mameyer <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/23 16:26:41 by mameyer           #+#    #+#             */
/*   Updated: 2017/05/23 16:45:31 by mameyer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_ls.h"

void		first_elem(t_lst *content, char *name, char *path, int *tmp)
{
	int		i;

	i = 0;
	content->name = ft_strdup(name);
	if (!(content->path = (char *)malloc(sizeof(char) * (ft_strlen(name) + 3))))
		error(1, "linked_lists.c");
	while (content->path[i])
	{
		content->path[i] = '\0';
		i++;
	}
	content->path = ft_strcpy(content->path, path);
	if (content->path[ft_strlen(path) - 1] != '/')
		content->path = ft_strcat(content->path, "/");
	content->path = ft_strcat(content->path, name);
	content->next = NULL;
	*tmp = 1;
}

void		new_elem(t_lst *content, char *name, char *path)
{
	int		i;

	i = 0;
	if (content->next)
		new_elem(content->next, name, path);
	else
	{
		if (!(content = malloc(sizeof(t_lst))))
			error(1, "linked_lists.c");
		content->name = ft_strdup(name);
		if (!(content->path = (char *)malloc(sizeof(char) *
						(ft_strlen(name) + 3))))
			error(1, "linked_lists.c");
		while (content->path[i])
		{
			content->path[i] = '\0';
			i++;
		}
		content->path = ft_strcpy(content->path, path);
		if (content->path[ft_strlen(path) - 1] != '/')
			content->path = ft_strcat(content->path, "/");
		content->path = ft_strcat(content->path, name);
	}
}
