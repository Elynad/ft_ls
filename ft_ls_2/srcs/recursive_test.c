/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   recursive_test.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mameyer <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/04 18:25:18 by mameyer           #+#    #+#             */
/*   Updated: 2017/04/18 11:26:30 by mameyer          ###   ########.fr       */
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

/*
char		**get_files(t_flags flags, char *path)
{
	t_folders		folders;
}
*/
/*
int			test_1(t_flags flags, char **arguments)
{
	int				i;
	struct stat		sb;
	char			**content;
	t_flist			fold;

	i = 0;
	while (arguments[i])
	{
		if (stat(arguments[i], &sb) == -1)
			error(3);
		if (S_ISDIR(sb.st_mode))
		{
			if (!(fold = (t_flist)malloc(sizeof(t_flist) * 1)))
				error(1);

//			content = 
		}
	}
	// FREE CONTENT
	return (0);
}
*/
int			test_2(t_flags flags, char **arguments, int index)
{
	if (arguments[index])
	{
		my_printf(arguments, flags);
//		ft_putstr(arguments[index]);
//		index++;
//		test_2(flags, arguments, index);
	}
	return (0);
}
