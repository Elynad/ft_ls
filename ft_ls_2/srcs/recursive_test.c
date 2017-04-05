/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   recursive_test.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mameyer <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/04 18:25:18 by mameyer           #+#    #+#             */
/*   Updated: 2017/04/05 17:09:26 by mameyer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_ls.h"

int			recursive_test(t_flags flags)
{
	t_folders		folders;

	init_folders_struct(&folders);
	if ((folders.rep = opendir("./")) == NULL)
		error(0);
	while ((folders.readfile = readdir(folders.rep)) != NULL)
		folders.index++;
	if (!(folders.names = (char **)malloc(sizeof(char *) * (folders.index + 1))))
		error(1);
	if (closedir(folders.rep) == -1)
		error(2);
	init_folders_struct(&folders);
	if ((folders.rep = opendir("./")) == NULL)
		error(0);
	folders.index = 0;
	while ((folders.readfile = readdir(folders.rep)) != NULL)
	{
		if (!(folders.names[folders.index] = (char *)malloc(sizeof(char *) \
				* (ft_strlen(folders.readfile->d_name) + 1))))
			error(1);
		folders.names[folders.index] = ft_strcpy(folders.names[folders.index], \
				folders.readfile->d_name);
		folders.names[folders.index][ft_strlen(folders.readfile->d_name)] = '\0';
		folders.index++;
	}
	folders.names[folders.index] = NULL;
	folders.index = 0;
	my_printf(folders.names, flags);
	return (0);
}
