/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   core_funcs.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mameyer <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/18 11:34:16 by mameyer           #+#    #+#             */
/*   Updated: 2017/04/19 15:15:25 by mameyer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_ls.h"

int		recursive_func(char *path, int index, t_flags flags)
{
	struct stat			sb;
	char				**content;

	content = open_directory(path, flags);
	if (index == 0)
		my_printf(content, flags);
	ft_putchar('a');
	while (content[index])
	{
		ft_putchar('b');
		if (stat(content[index], &sb) == -1)
			error(3);
		if (S_ISDIR(sb.st_mode) && index >= 2)
		{
			ft_putchar('c');
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

	/*
	if (index == 0)
	{
		if (!farg[1])
			my_printf(open_directory("./", flags), flags);
		else
			my_printf(farg, flags); // Print folder content
	}
	while (farg[index])
	{
		if (stat(farg[index], &sb) == -1)
			error(3);
		if (S_ISDIR(sb.st_mode) && (strcmp(farg[index], "./") != 0)
				&& (strcmp(farg[index], "..") != 0)
				&& (strcmp(farg[index], ".") != 0))
		{
			ft_putstr("\n\n");
			ft_putstr(farg[index]);
			ft_putstr(":\n");
			ft_putchar('b');
			recursive_func((open_directory(farg[index], flags)), 0, flags);
			ft_putchar('c');
		}
		index++;
	}
	*/

/*
int		recursive_func(char **farg, int index, int a)
{
	while (farg[index])		// First while => write folder content
	{
		ft_putstr(farg[index]);
		ft_putchar('\n');
		index++;
	}
	if (!farg[index])
		index = 0;
	while (farg[index])		// Second while => goes into the folders recursively
	{
		ft_putstr(farg[index]);
		index++;
	}
	if (!farg[index])
		a = 1;
	if (a == 0)
		recursive_func(farg, index, a);
	return (0);
}
*/

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
