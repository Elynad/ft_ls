/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_time.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mameyer <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/20 14:27:13 by mameyer           #+#    #+#             */
/*   Updated: 2017/06/22 15:05:40 by mameyer          ###   ########.fr       */
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
		next_time_sort(list, list, name, path);
	else if (flags.f_t == 1 && flags.f_r == 1)
	{
		// reverse sort time
	}
	else if (flags.f_t == 0 && flags.f_r == 1)
		next_reverse(list, name, path);
	else
		next(list, name, path);
}
