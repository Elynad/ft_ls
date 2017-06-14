/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   other.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mameyer <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/14 14:26:01 by mameyer           #+#    #+#             */
/*   Updated: 2017/06/14 17:18:52 by mameyer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_ls.h"

char		*get_name(char *path)
{
	char		*str;
	int			i;
	int			k;

	k = 0;
	i = ft_strlen(path);
	while (i > 0 && path[i] != '/')
		i--;
	if (!(str = (char *)malloc(sizeof(char) * (ft_strlen(path) - i))))
		error(0, "other.c, get_name func");
	while (path[i + k])
	{
		str[k] = path[i + k];
		k++;
	}
	str[k] = '\0';
	return (str);
}

void		get_highest_dep(t_lst *list, long *dep)
{
	struct stat			sb;

	if (stat(list->path, &sb) == -1 && lstat(list->path, &sb) == -1)
		perror(list->path);
	else
	{
		if (sb.st_nlink > *dep)
			*dep = sb.st_nlink;
	}
	if (list->next)
		get_highest_dep(list->next, dep);
}
