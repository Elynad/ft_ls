/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   other.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mameyer <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/19 13:40:44 by mameyer           #+#    #+#             */
/*   Updated: 2017/04/21 17:43:54 by mameyer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_ls.h"

int			find_index(t_flags flags, char **str)
{
	int		index;
	int		i;

	i = 0;
	index = 0;
	while (str[index][0] == '.' && flags.f_a == 0)
		index++;
	return (index);
}

char		*clear_str(char *str)
{
	int		i;

	if (str)
	{
		i = 0;
		while (str[i])
		{
			str[i] = '\0';
			i++;
		}
	}
	return (str);
}

char		*set_newpath(char *oldpath, char *newpath)
{
	char	*str;

	if (!(str = (char *)malloc(sizeof(char) * \
					(ft_strlen(oldpath) + ft_strlen(newpath) + 3))))
		exit(0);
	str = clear_str(str);
	str = ft_strdup(oldpath);
	str = ft_strcat(str, "/");
	str = ft_strcat(str, newpath);
	return (str);
}

int			check_if_empty(char *path, t_flags flags)
{
	t_fold		fold;

	init_fold_struct(&fold);
	if ((fold.rep = opendir(path)) != NULL)
	{
		while ((fold.readfile = readdir(fold.rep)) != NULL)
			fold.index++;
	}
	if (fold.index == 2)
		return (1);
	else
		return (0);
}
