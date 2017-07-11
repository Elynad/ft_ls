/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_total.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mameyer <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/08 16:14:17 by mameyer           #+#    #+#             */
/*   Updated: 2017/07/08 16:21:42 by mameyer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_ls.h"

int		get_total(t_lst *list)
{
	int		total;

	total = 0;
	get_total_2(list, &total);
	return (total);
}

void	get_total_2(t_lst *list, int *total)
{
	struct stat		sb;

	if (stat(list->path, &sb) == -1 && lstat(list->path, &sb) == -1)
		perror(list->path);
	*total += sb.st_blocks;
	if (list->next)
		get_total_2(list->next, total);
}
