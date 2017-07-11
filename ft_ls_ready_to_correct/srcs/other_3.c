/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   other_3.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mameyer <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/10 18:53:58 by mameyer           #+#    #+#             */
/*   Updated: 2017/07/11 17:36:28 by mameyer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_ls.h"

void		permission_denied(char *path)
{
	ft_putstr_fd("ft_ls: ", 1);
	ft_putstr_fd(path, 1);
	ft_putstr_fd(": Permission denied\n\n", 1);
}

t_lst		*set_elem(char *path, t_flags flags)
{
	t_lst		*new_elem;

	if (!(new_elem = malloc(sizeof(t_lst))))
		error("malloc failed");
	new_elem->next = NULL;
	new_elem->name = ft_strdup(path);
	new_elem->path = ft_strdup(path);
	my_printf(new_elem, flags, 1);
	return (new_elem);
}

int			sub_core(struct stat sb, char *path, t_lst **list, t_flags flags)
{
	if ((S_ISDIR(sb.st_mode) || ft_strcmp(path, "./") == 0)
			&& sb.st_mode & S_IRUSR)
		sub_core_isdir(list, sb, path, flags);
	else if ((S_ISDIR(sb.st_mode) || ft_strcmp(path, "./") == 0)
			&& !(sb.st_mode & S_IRUSR))
		permission_denied(path);
	else
		return (1);
	return (0);
}
