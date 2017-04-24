/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   core_functions.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mameyer <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/24 14:22:19 by mameyer           #+#    #+#             */
/*   Updated: 2017/04/24 20:03:15 by mameyer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_ls.h"

int		recursive_func(char *path, int index, t_flags flags)
{
	struct stat			sb;
	char				**content;
	char				*newpath;

	if (stat(path, &sb) == -1)
		error(0, path);
	else if (S_ISDIR(sb.st_mode))
	{
		content = open_directory(path, flags);
		if (index == 0 && content != 0)
			my_printf(content, flags);
		if (flags.f_R != 1)
			return (0);
		while (content[index])
		{
			newpath = set_newpath(path, content[index]);
			if (stat(newpath, &sb) == -1)
				error(5, "");
			if (S_ISDIR(sb.st_mode) && index >= 2)
			{
				if ((content[index])
						&& ((content[index][0] != '.' && flags.f_a == 0)
						|| (flags.f_a == 1)))
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
	return (0);
}

char	**open_directory(char *path, t_flags flags)
{
	t_fold		fold;

	init_fold_struct(&fold);
	// missing
	if ((fold.rep = opendir(path)) == NULL)
		error(4, "");
	while ((fold.readfile = readdir(fold.rep)) != NULL)
		fold.index++;
	if (!(fold.names = (char **)malloc(sizeof(char *) * (fold.index + 1))))
		error(2, "");
	if (closedir(fold.rep) == -1)
		error(3, "");
	init_fold_struct(&fold);
	if ((fold.rep = opendir(path)) == NULL)
		error(4, "");
	while ((fold.readfile = readdir(fold.rep)) != NULL)
	{
		fold.names[fold.index] = ft_strdup(fold.readfile->d_name);
		fold.index++;
	}
	while (fold.names[fold.index])
	{
		fold.names[fold.index] = NULL;
		fold.index++;
	}
	return (fold.names);
}


