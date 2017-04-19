/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   core_funcs.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mameyer <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/18 11:34:16 by mameyer           #+#    #+#             */
/*   Updated: 2017/04/19 17:25:08 by mameyer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_ls.h"

int		recursive_func(char *path, int index, t_flags flags)
{
	struct stat			sb;
	char				**content;
	char				*newpath;

	content = open_directory(path, flags);
	if (index == 0)
		my_printf(content, flags);
	while (content[index])
	{
		newpath = clear_str(newpath);
		newpath = ft_strdup(path);
		newpath = ft_strcat(newpath, "/");
		newpath = ft_strcat(newpath, content[index]);
		if (stat(newpath, &sb) == -1)
			error(1);
		if (S_ISDIR(sb.st_mode) && index >= 2)
		{
			ft_putchar('\n');
			ft_putstr(content[index]);
			ft_putstr(":\n");
			recursive_func(content[index], 0, flags);
		}
		index++;
	}
	ft_putchar('d');
//	free(content);
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

char	**open_directory(char *path, t_flags flags)	// GETS ALL THE CONTENT OF A DIR INTO A **CHAR
{
	t_fold			fold;

	init_fold_struct(&fold);
	if ((fold.rep = opendir(path)) == NULL)
		error(1);
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
	fold.index = 0;

	return (fold.names);
}
