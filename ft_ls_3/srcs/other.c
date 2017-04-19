/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   other.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mameyer <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/19 13:40:44 by mameyer           #+#    #+#             */
/*   Updated: 2017/04/19 17:32:36 by mameyer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_ls.h"

int			find_index(t_flags flags)
{
	int		index;

	index = 0;
	if (flags.f_a == 1)
		index = 2;
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
