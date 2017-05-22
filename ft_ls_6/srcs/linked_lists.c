/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   linked_lists.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mameyer <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/20 17:29:50 by mameyer           #+#    #+#             */
/*   Updated: 2017/05/22 17:46:14 by mameyer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_ls.h"

void		first_elem(t_lst *list, char *name, char *path, int *i)
{
	list->name = ft_strdup(name);
	list->path = set_path(path, name);
	list->next = NULL;
	*i = 1;
}

void		new_elem(t_lst *list, char *name, char *path)
{
	if (list->next != NULL)
		new_elem(list->next, name, path);
	else
	{
		if (!(list->next = malloc(sizeof(t_lst))))
			error_1(2, "linked_lists - line 27");
		list->next->name = ft_strdup(name);
		list->next->path = set_path(path, name);
		list->next->next = NULL;
	}
}

char		*set_path(char *path, char *name)
{
	size_t		size;
	char		*str;
	int			i;
	int			j;

	i = 0;
	j = 0;
	size = ft_strlen(path) + ft_strlen(name) + 3;
	if (!(str = (char *)malloc(sizeof(char) * size)))
		error_1(2, "linked_lists.c - line 35");
	while (str[i])
	{
		str[i] = '\0';
		i++;
	}
	str = ft_strcpy(str, path);
	while (str[i])
		i++;
	if (path[ft_strlen(path) - 1] != '/')
	{
		str[ft_strlen(path)] = '/';
		i++;
	}
	while (name[j])
	{
		str[i + j] = name[j];
		j++;
	}
	str[i + j] = '\0';
	return (str);
}
