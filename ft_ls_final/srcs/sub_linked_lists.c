/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sub_linked_lists.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mameyer <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/22 15:25:37 by mameyer           #+#    #+#             */
/*   Updated: 2017/07/08 16:04:51 by mameyer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_ls.h"

void		sub_next_1(t_lst *elem, char *name, char *path)
{
	t_lst		*tmp;

	if (!(tmp = malloc(sizeof(t_lst))))
		perror("malloc new link");
	tmp->name = ft_strdup(elem->name);
	tmp->path = ft_strdup(elem->path);
	tmp->next = elem->next;
	free(elem->name);
	elem->name = ft_strdup(name);
	free(elem->path);
	elem->path = set_path(name, path);
	elem->next = tmp;
}

void		sub_set_path(char **str, int index, char *s2)
{
	int		j;

	j = 0;
	while (s2[j])
	{
		*str[index + j] = s2[j];
		j++;
	}
	while (*str[index + j])
	{
		*str[index + j] = '\0';
		j++;
	}
}
