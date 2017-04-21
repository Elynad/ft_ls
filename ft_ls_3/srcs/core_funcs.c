/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   core_funcs.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mameyer <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/18 11:34:16 by mameyer           #+#    #+#             */
/*   Updated: 2017/04/21 17:44:54 by mameyer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_ls.h"

int		recursive_func(char *path, int index, t_flags flags)
{
	struct stat			sb;
	char				**content;
	char				*newpath;

	if (stat(path, &sb) == -1)
		error(3);
	if (S_ISDIR(sb.st_mode))
	{
		content = open_directory(path, flags);
		// TEST
		int i = 0;
		while (content[i])
		{
			i++;
		}
		if (i == 2)
			return (0);
		// END TEST
		if (index == 0 && content != 0)
			my_printf(content, flags);
		if (flags.f_R != 1)
			return (0);
		while (content[index])
		{
			newpath = set_newpath(path, content[index]);
			if (stat(newpath, &sb) == -1)
				ft_putchar('z');
//				no_fildir(newpath);
			if (S_ISDIR(sb.st_mode) && index >= 2)
			{
				if (content[index][0] != '.' && flags.f_a == 0)
				{
					ft_putchar('\n');
					ft_putstr(content[index]);
					ft_putstr(":\n");
				}
				recursive_func(content[index], 0, flags);
			}
			index++;
		}
	}
	else
		ft_putstr(path);
	// free
	return (0);
}

int		simply_dir(char **farg, t_flags flags)
{
	int		i;

	i = 0;
	while (farg[i])
	{
		my_printf((open_directory(farg[i], flags)), flags);
		i++;
	}
	return (0);
}

char	**open_directory(char *path, t_flags flags)
{
	t_fold			fold;

	init_fold_struct(&fold);
	if ((fold.rep = opendir(path)) == NULL)
	{
		if (!(fold.names = (char **)malloc(sizeof(char *) * 2)))
			error(0);
		fold.names[0] = ft_strdup(path);
		fold.names[1] = NULL;
		return (fold.names);
	}
	while ((fold.readfile = readdir(fold.rep)) != NULL)
		fold.index++;
	if (!(fold.names = (char **)malloc(sizeof(char *) * (fold.index + 1))))
		error(0);
	if (closedir(fold.rep) == -1)
		error(2);
	init_fold_struct(&fold);
	if ((fold.rep = opendir(path)) == NULL)
		error(1);
	while ((fold.readfile = readdir(fold.rep)) != NULL)
	{
		if (!(fold.names[fold.index] = (char *)malloc(sizeof(char *) * \
						(ft_strlen(fold.readfile->d_name) + 1))))
			error(0);
		fold.names[fold.index] = ft_strcpy(fold.names[fold.index], \
				fold.readfile->d_name);
		fold.names[fold.index][ft_strlen(fold.readfile->d_name)] = '\0';
		fold.index++;
	}
	fold.names[fold.index] = NULL;
	return (fold.names);
}
